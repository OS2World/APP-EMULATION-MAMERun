MAMERun Beta 6     Copyright 1999-2000 by Jason R Stefanovich
                            

*****************DISCLAIMER*********************
This program is provided "AS IS".  There is NO warranty
or claim of fitness for use, expressed or implied.
Anything you do with this program is AT YOUR OWN RISK!
************************************************

What is it:
MAMERun is a FREEWARE PM frontend for the DOS version of MAME
(Multi. Arcade Machine Emulator).  A Frontend is a program that
makes it easier for the user to interface with their application,
which usually has a command line interface.  MAME is a very popular
emulator that allows you to run thousands of classic arcade
games on your PC (if you own the ROMs).  You can find the MAME
homepage at http://www.mame.net/.  The Official 
(and very good) OS/2 PM port of MAME was done by
Marty Amodeo and is at http://emuos2.vintagegaming.com/.
Of courses you can find the MAMERun Homepage and the most
up to date releases at http://home1.gte.net/stefanj/mamerun.htm.

Why:
I wrote MAMERun because I wanted an alternative to running the
PM version without having to reboot back to Windows or type
in really long command strings.  Some people have problems
with their video and sound in PM.  For me it was the fact that
my poor system just couldn't chug along fast enough too keep
up.  I also like to tweak stuff.  I've included most of the options
that MAME has (some 30 of them) so you can fiddle all you like.
You may find that using the DOS version of MAME under OS/2
works better for you, or maybe not.  Just keep having fun!!

Requirements:
* OS/2 
* MAME for DOS (I used version .37 beta 7)
* I STRONGLY SUGGEST YOU USE MAME .36 beta 12 OR HIGHER BECAUSE IT CORRECTS A Y2K BUG!
* DOS Support installed
* RexxUtil
* Joystick device driver for joystick support (download from hobbes or DDPAK)
   For better performance I recommend using either Vesa J„„skel„inen's or J Da Silva's joystick
   driver.  You can find them on the MAMERun Contest page HTTP://home1.gte.net/stefanj/. or on HOBBES.
* ROMs (DO NOT ASK ME FOR, OR WHERE TO GET ROMS!!)

Whats New Beta 6
* Added code to verify correct path for MAME.exe
* Added checking for ROM Sets
* Now asks user if they want clones listed in Hotlist
* Updated About message and added mailto: button
* Will now recreate MAMERun.cfg if it does not exist
* MAMERun bitmaps are now embedded resources
* Added error log viewing
* Added readme viewing
* Minor interface changes
* Fixed some minor bugs
* Checked for compatibility with latest release of MAME (v.37b7)
* Checked for compatibility with OS/2 4.5 (FP13 and higher)

Whats New Beta 5a:
* Fixed nasty bug that would crash the ROM check routines if the alternate ROM dir was blank
* Made cosmetic changes to main graphic and Config menu
* Tested for compatability with latest release of MAME (v.36b13)

Whats New Beta 5:
* Changed the interface a bit to make it easier to read and fixed some minor bugs
* Removed the tab stops from all objects except the Hotlist
* Updated the main menu and popup
* Added support for ROM and sample checking
* Fixed bug with alternate ROM dir. and duplicate names
* All ROMs in the alternate dir are now identified with the suffix '[alt]'
* Fixed timing issues with some processes
* Added a 'Check for updates' button

Whats New Beta 4:
* Added the ability to set custom configs for each game.
* Fixed various bugs
* Tested for compatability with latest release of MAME (v.36b10)

Whats New Beta 3:
* Hotlist now shows actual game names
* Added extra options for vector games
* Added option to play back recorded files
* Added support for windowed modes
* Added support for external commands
* Cleaned up the interface
* Removed the VPOBJ library
* No longer need the prebuilt mamerun.ini and defaultmamerun.ini
* Fixed misc. small bugs

Whats New Beta 2:
* Fixed bug with the "Flip Y" button
* Fixed clipping and scaling problem with MAMERun bitmap
* Removed the need for an external bitmap
* Removed the maximize button from all windows
* Removed the minimize button from modal windows
* Added Norm Ross's STARTD program
* Customized the DOS environment to allow the running of large ROMs
   and enhance emulation speed


Installation:
The files that should be included are..
MAMERun.exe            (the frontend program, run this!)
readme.txt               (this file)
pong.zip                   (placeholder file to play pong, put in one of your ROM dirs)
startd.exe                (enhanced replacement for the START program)
startd.zip                 (full distribution with source)
configs subdir           (directory where all custom configurations are saved)
dir.txt                      (tells you what the configs subdir is for)
file_id.diz                 (bbs description file)
license.txt                (license for MAMERun)


If you get a copy of this program and any of these files are
missing, please let me know.

* If you are using a version of MAMERun previous to beta 3,
you must delete the mamerun.ini and defaultmamerun.ini
files because the format has changed.

Simply unzip the archive into a directory of your choice and
run MAMERun.exe.  The first time you run the program it
will ask you to open the Config window and tell it
where MAME is, if you have an alternate ROM directory
and if you want to run any additional programs.
Once you have set up your directories, Build Hotlist to give
you a list of all your roms. Select the settings you want to use
and Save Settings if you want them to be saved for the next
session.

Operation:
MAMERun comes preconfigured with the default settings
for MAME.  Most people will want to change the soundcard
setting and turn off scanlines.  To run your ROMs simply
double-click on the entry in the Hotlist.  Unlike some other
frontends, MAMERun makes no changes to mame.cfg.  That
means that using MAMERun has no effect on the use of
any other frontend with MAME or any changes that you may
make to mame.cfg.  To setup a custom configuration for a
ROM:  Highlight it in the Hotlist, set the configuration the
way you want, right click on the ROM and select Save Custom
Config. To reset the ROM to your default settings, right click
on it and select Reset to Default.

Bugs, Errors, Problems:
****** Make sure you have at least version .36 of MAME. ******
Although MAMERun may work perfectly with earlier versions,
it was designed with at least MAME .36 Beta X in mind.

Some of the settings that MAME allows will not work well or at all
for some people:

*  I have labeled the items RED which may cause 
SERIOUS problems.  A Serious problem could be
a hang, crash or, in the case of VGA Freq., even destruction of hardware.
I have had no problems with these items, that doesn't mean that
you will be as lucky.  Please do not use these unless you know what
you are doing or are willing to take the risk.

*  I have labeled the items BLUE which may cause MODERATE problems.
A Moderate problem may be a DOS session crash or hang or
it just won't work at all.

*  I have added help lines for all the options with some recommendations.
Please note that I did not make up these settings, they are from MAME's
command line configuration options.  Please consult the MAME readme
to learn more about them.

*  I have left the debug windows enabled for this build.  If the program
crashes please send me a copy of the debug output and what you were
doing when it crashed.

*  If by some chance MAMERun seems to be messing up your saved settings,
the ini may be corrupt.  Just delete mamerun.ini, the next time you start
MAMERun all the settings will be back to the defaults.  NOTE:  You still
have to save the settings for them to take effect in the next session.

*  If the DOS session won't open, try closing MAMERun and deleting mamerun.cfg.
When you next run MAMERun it will create a new config. file.

*  Because I didn't like the way MAME's -romdir command worked, I wrote my
own code for alternate ROM directories.  It will attempt to copy the mame.cfg
to the alternate dir.  If this directory is on read only media it may cause an
error or the behavior of MAME may not be as expected.

*  If MAME seems not to be running as you have configured it in MAMERun,
enable the Ignore Config setting it the Misc section.

*  Some games need more memory than the default DOS environment in OS/2
gives them.  There is no need to modify your default DOS environment.
I am using STARTD to open a DOS session.  STARTD allows the
configuration of the DOS environment before the VDM starts.  The file
mamerun.cfg contains the DOS environment settings that MAMERun uses.  If you
do not like these settings you can change them.  See the STARTD readme
for more info.

*  If you need/want to run a utility, mixer, vbe extentions....etc, use the External
Command option in the Config menu.  Whatever is entered as an External
Command is passed to the DOS Command Interpreter after the Autoexec.bat
and before MAME starts.

*  Several people have had problems getting sound with their Soundblaster
cards (or SB emulators) with MAMERun.  To correct this, you need pass
the SET BLASTER environment variables to MAME.  There are two ways
you can do this.
1.  Put the environment variables in your Autoexec.bat
2.  create a separate batch file and use the External Command option
    in the Config menu to run it before MAME starts.

The Blaster Environment variables and their options: 

        SET SOUND=C:\SB\ 
        Path to audio card config programs, this is not needed 

        SET BLASTER=A220 I5 D1 H5 P330 T6 
        Where: 
        A is the hex IO address 
        I is the interrupt 
        D is the low DMA channel 
        H is the high DMA channel 
        P is th MPU-401 UARTs address 
        T is the card type 

        SET MIDI=SYNTH:1 MAP:E MODE:0 
        Where: 
        Synth=1 stereo, 2 MIDI port 
        MAP=G general, E extended, B basic 
        MODE=0 general, 1 standard, 2 MT-32

*  A word about windowed modes.  Although I have provided the ability for
MAMERun to start MAME in a window, that doesn't mean it will work on your
system.  Running MAME in a window is very video adaptor and driver dependent.
Try different resolutions and color depths to see what may work for you.

*  Checking All ROMs/Sets.  If you break out of checking all ROMs by closing the DOS
window, MAMERun will hang while waiting for an exit notification from the DOS program.
If you hang MAMERun it will not bother any other processes and you will be able
to close it normally from the window list or warpcenter.
The only way to break out of this process without hanging MAMERun
is to hit CTRL-BREAK, wait till mame restarts, then hit CTRL-BREAK again.

*  MAMERun is able to run many different versions of MAME (amame, pmame, mamek6...etc),
but does not support any additional command line switches that these
MAME versions may have.  You do not have to change the name of these executables,
simply pick the version of MAME that you wish to run in the Config menu.

*  Navigating the Hotlist can be done with arrow and page keys.  To skip to a ROM
quickly, type the first character of it's name and you will be brought to the first ROM
that starts with that character.

WIP:
1.  ** Done ** The Hotlist does not yet check the validity of ROMs before it loads them,
if a ROM doesn't work it may be because it's bad, you selected an incorrect
mode or your ROM is incorrectly named.  I'm still working on this.  The problem
is that I have many ROMS that fail MAME's -verifyroms command but run perfectly.
I haven't decided how I'm going to deal with this yet.
3.  Want to add screen captures for each ROM, need to find a tool to load PNG files.
4.  ** On hold indef. ** More than one alternate ROM directory.
5.  ** Done ** Add the remaining MAME options.  There are only a couple more obscure options
that MAME supports that are not in MAMERun.  If you really want/need one of these,
write to me and I will add it.
6.  ** Done **  Add support for individual configs per ROM.
7.  Refine the current code (always!!)
8.  Cleanup this damn readme and the web page.
9.  Build a real help file.

Thanx:
The Official MAME Team for building an awesome emu
Marty Amodeo for his great OS/2 port
TrueSpectra who's cool graphics program I used for my BMP
Frank Beythien for pointing me in the right direction
Norm Ross for his easy to use STARTD program
Mesterh zy Attila for giving me the idea for the External Command
My wife for putting up with me sitting in front of this "Damn Box"

Comments, Questions or Suggestions?
Send 'em to stefanj@gte.net
or snailmail:
2156-A Hall St
Wahiawa, HI 96786
