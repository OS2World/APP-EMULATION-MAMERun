/*
 *  STARTD:  A simple program to start a DOS session under OS/2 2.0.  
 *           This program can be run from an OS/2 command prompt
 *
 *  Last Modfied: 07/07/92
 *
 *  Author: Norm Ross
 *  
 *  Using the example code for BOOTA.C found in IBM DOCUMENT GBOF-2254
 *
 *  This was written mainly to provide access to DOS SETTINGS for
 *  VDM sessions. Since I have disabled the WPS to free up the space,
 *  I can't specify DOS settings for my favorite DOS apps.
 *  STARTD is not meant to replace START but it does many of
 *  the same things...
 *
 *  If you change this program and re-distribute it please leave this
 *  header intact and send the readme file with it.
 * 
 *  MODIFICATION HISTORY
 *   
 *  07-Jul-1992  Norm Ross, npross@undergrad.uwaterloo.ca
 *     1.00 : Initial version
 */

#define INCL_DOSSESMGR
#define INCL_DOSMISC
#define INCL_DOSPROCESS
#include <os2.h>
#include <stdio.h>
#include <string.h>

PBYTE readEnv(PSZ pFileName);

PSZ pBootFailure = "Session could not be started.\r\n";
char szPgmInputs[256];
char szDosPgmInputs[256];

STARTDATA startd;                  /* Session start information */
ULONG SessionID;                   /* Session and Process ID for new session*/
PID ProcessID;

void main(int argc, char *argv[])
{
  USHORT       rc;
  USHORT       flagWin = 0, flagFs = 0, flagKeep = 0, flagNoCmd = 0;

  /* ---- init startd struct defaults */
  startd.Length                   = sizeof(STARTDATA);
  startd.Related                  = SSF_RELATED_INDEPENDENT;
  startd.FgBg                     = SSF_FGBG_FORE;
  startd.TraceOpt                 = SSF_TRACEOPT_NONE;
  startd.PgmTitle                 = NULL;
  startd.PgmName                  = NULL;
  startd.PgmInputs                = NULL;
  startd.TermQ                    = NULL;
  startd.Environment              = NULL;
  startd.InheritOpt               = SSF_INHERTOPT_PARENT;
  startd.SessionType              = SSF_TYPE_DEFAULT;
  startd.PgmControl               = SSF_CONTROL_VISIBLE;


  /* ------ Process args */
  while(--argc > 0) {
    char *arg;

    switch(**++argv) {
    case '\"':
	startd.PgmTitle = strtok(*argv, "\"");
	break;
    case '-':
    case '/':
      arg = (*argv)+1;
      if (strlen(arg) == 1) {
	switch(*arg) {
	case 'n':
	case 'N': flagNoCmd = 1; break;
	case 'k':
	case 'K': flagKeep = 1; break;
	case 'c':
	case 'C': break;
	case 'f':
	case 'F': startd.FgBg = SSF_FGBG_FORE; break;
	case 'B':
	case 'b': startd.FgBg = SSF_FGBG_BACK; break;
	case 'i': 
	case 'I': startd.InheritOpt = SSF_INHERTOPT_SHELL; break;
	case '?': usage(); break;
	default:
	  fprintf(stderr, "Unrecognized option: %s\n", arg);
	  usage();
	  break;
	}
      } else if (strcasecmp(arg, "DOS") == 0) { 
	startd.SessionType = SSF_TYPE_VDM;
      } else if (strcasecmp(arg, "WIN") == 0) {
	flagWin = 1;
      } else if (strcasecmp(arg, "WAIT") == 0) {
	startd.Related = SSF_RELATED_CHILD;
      } else if (strcasecmp(arg, "FS") == 0) {
	flagFs = 1;
      } else if (strcasecmp(arg, "FG") == 0) {
	startd.FgBg = SSF_FGBG_FORE; 
      } else if (strcasecmp(arg, "BG") == 0) {
	startd.FgBg = SSF_FGBG_BACK;
      } else if (strcasecmp(arg, "MAX") == 0) {
	startd.PgmControl |= SSF_CONTROL_MAXIMIZE;
      } else if (strcasecmp(arg, "MIN") == 0) {
	startd.PgmControl |= SSF_CONTROL_MINIMIZE;
      } else if (strcasecmp(arg, "INV") == 0) {
	startd.PgmControl |= SSF_CONTROL_INVISIBLE;
      } else if (strcasecmp(arg, "PM") == 0) {
	startd.SessionType = SSF_TYPE_PM;
      } else if (strncasecmp(arg, "pos", 3) == 0) {
	char *s = strtok(arg, "=");

	/* ---- I really should check strtok's return... */
	startd.PgmControl |= SSF_CONTROL_SETPOS;
	startd.InitXPos = atoi(strtok(NULL, ","));
	startd.InitYPos = atoi(strtok(NULL, ","));
	startd.InitXSize = atoi(strtok(NULL, ","));
	startd.InitYSize = atoi(strtok(NULL, ""));
      } else if (strcasecmp(arg, "PGM") == 0) {
	char *p = szPgmInputs;
	/* ---- strip quotes from name if there are any */
	startd.PgmName = strtok(*argv, "\"");
	  
	/* ---- cat the rest of the args together to pass to pgm */
	while (argc > 1) {
	  argc--;
	  argv++;
	  strcpy(p, *argv);
	  p += strlen(*argv);
	  *p++ = ' '; /* put spaces between the args */
	}
	*p = '\0';
	startd.PgmInputs = szPgmInputs;
	break;
      } else if (strcasecmp(arg, "ICON") == 0) {
	startd.IconFile = *++argv;
	argc--;
      } else if (strcasecmp(arg, "SF") == 0) {
	char *fname = *++argv;
	argc--;
	if (access(fname, 0)) {
	  fprintf(stderr, "Session File %s not found\n", fname);
	}
	startd.Environment = readEnv(fname);
      } else {
	printf("Unrecognized option: %s\n", arg);
	usage();
      }
      break;

    default: 
	{
	  char *p = szPgmInputs;
	  startd.PgmName = *argv;
	  
	  /* ---- cat the rest of the args together to pass to pgm */
	  while (argc > 1) {
	    argc--;
	    argv++;
	    strcpy(p, *argv);
	    p += strlen(*argv);
	    *p++ = ' '; /* put spaces between the args */
	  }
	  *p = '\0';
	  startd.PgmInputs = szPgmInputs;
	  break;
	}

    } /* switch */
  } /* while */

  /* ------ Start thru Command processor */
  if ((startd.PgmName!=NULL)&&(startd.SessionType!=SSF_TYPE_PM)&&(!flagNoCmd)){
    if (flagKeep)
      strcpy(szDosPgmInputs, "/k ");
    else
      strcpy(szDosPgmInputs, "/c ");
    strcat(szDosPgmInputs, startd.PgmName);
    strcat(szDosPgmInputs, " ");
    strcat(szDosPgmInputs, startd.PgmInputs);
    startd.PgmInputs = szDosPgmInputs;
    startd.PgmName = NULL;
  }
      
  /* ------ Set the correct session type */     
  if (flagWin) {
    switch(startd.SessionType) {
    case SSF_TYPE_DEFAULT: startd.SessionType = SSF_TYPE_WINDOWABLEVIO; break;
    case SSF_TYPE_VDM: startd.SessionType = SSF_TYPE_WINDOWEDVDM; break;
    case SSF_TYPE_PM: break;
    } 
  } else if (flagFs) {
    switch(startd.SessionType) {
    case SSF_TYPE_DEFAULT: startd.SessionType = SSF_TYPE_FULLSCREEN; break;
    case SSF_TYPE_VDM: break;
    case SSF_TYPE_PM: break;
    }
  }

  /* ------ Start the Session */
  rc = DosStartSession( &startd, &SessionID, &ProcessID );

  if(rc) {
    /* ------ Print out failure message */
    DosPutMessage(1,strlen(pBootFailure),pBootFailure);
  } else if (startd.Related == SSF_RELATED_CHILD) {
    /* ------ Wait for child to finish */
    RESULTCODES resultcodes;
    PID pid;

    /* ------ Shot in the dark... Please fix and tell me about it*/
    DosWaitChild(1, 1, &resultcodes, &pid, ProcessID);
  }
    

return;
}

#define MAXENV 4096
PBYTE readEnv(PSZ fname) {
  FILE *fptr;
  PBYTE env = (PBYTE)malloc(MAXENV);
  PBYTE p = env;

  fptr = fopen(fname, "r");
  if (fptr == (FILE *)NULL) {
    fprintf(stderr, "\nFile %s cannot be found\n");
    exit(-1);
  }

  while (fgets(p, 80, fptr)) {
    p+=strlen(p);
    *(p-1)='\0';
    if (p>env + 4096) {
      fprintf(stderr, "ERROR: too many settings\n");
      fflush(stderr);
      exit(-1);
    }
  }

  realloc(env, p-env);

return(env);
}

usage( void ) {
  fprintf(stderr, "STARTD VERSION 1.0 by Norm Ross Copyright (c) 1992\n\n");
  fprintf(stderr, "startd [\"program title\"] [/BG /C /DOS /F /FS /I /ICON iconfile /INV /K /MAX\n\t /MIN /PGM POS=x,y,x1,y1 /SF settingsfile /WIN] [command ...]\n\n");
  fprintf(stderr, "\t/B[G]\t start session in background\n");
  fprintf(stderr, "\t/C\t close session upon completion\n");
  fprintf(stderr, "\t/DOS\t start a dos session\n");
  fprintf(stderr, "\t/F[G]\t start session in foreground\n");
  fprintf(stderr, "\t/FS\t start a full screen session\n");
  fprintf(stderr, "\t/I\t sets SSF_INHERTOPT_SHELL\n");
  fprintf(stderr, "\t/ICON\t uses the specified icon file\n");
  fprintf(stderr, "\t/INV\t start the application invisibly\n");
  fprintf(stderr, "\t/K\t keep the session around after it is finished\n");
  fprintf(stderr, "\t/MAX\t start maximized\n");
  fprintf(stderr, "\t/MIN\t start minimized\n");
  fprintf(stderr, "\t/N\t don't start indirectly through command processor\n");
  fprintf(stderr, "\t/PGM\t the next argument is the program name\n");
  fprintf(stderr, "\t/PM\t start a PM program\n");
  fprintf(stderr, "\t/POS=x,y,x1,y1\t specify window position and size\n");
  fprintf(stderr, "\t/SF\t read the specified dos settings file\n");
  fprintf(stderr, "\t/WIN\t start a windowed session\n");
  fprintf(stderr, "\t/WAIT\t doesn't work\n");
  exit(1);
}
