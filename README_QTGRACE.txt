General Notes on Version 0.1.5:

Dear User or Developer;

Thank you for your interest in my Qt-version of Grace!
In case you do not know already: Grace is a program to plot data and analyze it.
Grace is based on xmgrace / xmgr and uses the motif-framework for the graphical user interface.
The Grace-website is: http://plasma-gate.weizmann.ac.il/Grace/
QtGrace is based on grace-5.1.22 but uses the Qt-framework from Nokia as a graphical user interface instead (Qt and their respective logos are trademarks of Nokia Corporation).
Although I have tested QtGrace for quite a while now there may still be some problems / bugs present. I recommend this version mainly for experienced Grace-users and developers. Everyone else may give it a try, but be sure to read the Grace documentation (and save often).

I hope this will be useful to someone else as well (I like my Qt-version of Grace :-) ).

I had problems using Grace on different operating systems. Since I had written some applications using the Qt-framework (which can be found on http://qt.nokia.com) I decided to modify the latest stable version of Grace (5.1.22) and replace all dialogs by equally looking Qt-replacements. I wanted to conserve the "look and feel" of Grace 5.1.22 because I wanted all Grace-users to be able to work with QtGrace immediately without having to adjust their workflow.

I altered most of the source-files and therefore changes in Grace have to be implemented manually. Since there seem to be no major development around Grace-5.1.22 I believe that this approach is acceptable for now. All development on Grace seems to be focused on version 6 (or 5.99) which has a fundamentally different internal architecture (I try to write an improved Qt-sublayer especially for Grace version 6 - but this is a different story). QtGrace is not compatible with Grace 5.99.

This version 0.1.2 of QtGrace is capable of most of the operations Grace 5.1.22 is able to do. Some functions are missing or work only on some platforms (see below). I have inserted a few extra functions I found helpful (see below). There are a few minor known problems (see below).

The internal procedures are the ones from Grace 5.1.22 (internal data management, calculations and so on). I have only recreated the user interface in Qt which makes it possible to compile QtGrace natively (!) on Windows, Mac OS X and Linux. You can load your old Grace-project files (usual extension: '.agr'). With Qt it is also possible to easily translate the user interface and make the language of the interface selectable (I have made an attempt for a test-translation to German. The file is included but very far (!!) from being complete. If there is someone out there willing to complete the german translation or generate a translation to any other language feel free to do so using the "Linguist" program included in the Qt-installation. If you send me the translation I will include it into the downloadable folder.).

At the moment I only provide the source code for QtGrace since I am not 100% sure which files are needed for every platform. Therefore everyone has to download Qt from Nokia as well (see below). As an additional download I also provide a binary-version for Windows for all Windows-users who just want to use QtGrace and are no developers. The dll-files in this zip-file are copyright by Nokia and part of Qt. I provide them just for convenience. Don't alter the structure or remove content from the folders.

I am always interested in hearing your opinion on QtGrace or in your bug-reports. Suggestions for improvements are welcome also!
To contact me please use email: andreas.f.winter@web.de

I hope you enjoy QtGrace!

Best regards
Andreas Winter (andwin)


Copyright and Licence-Terms:

Copyright (C) 2008-2011 by Andreas Winter
andreas.f.winter@web.de

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the
Free Software Foundation, Inc.,
59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.


How to build QtGrace:

QtGrace is based on the Qt-Framework which has to be obtained via http://qt.nokia.com.
Please use at least version 4.6 (or newer) of Qt to compile QtGrace!
Please install the Qt-SDK which includes the Qt-Creator IDE. If you are an experienced developer, you may also be able to compile QtGrace without the Qt-Creator, but I will not describe how to do so here.
Since you have extracted this folder you may notice, that there are some sub-folders. It is important for QtGrace to keep the structure of this folder as it is in order to find some files at runtime. I have also included the original source-code-zip-file from grace-5.1.22 as a tar-archive. You will not have to extract it. This is included just for completeness and for developers use in case someone needs it. 
I assume in the following part, that you have installed Qt and you have got a fully functional Qt-Creator. 
To compile QtGrace: 
First step: Open Qt-Creator and do File->"Open File or Project…" (you may have to specify the file format as "Qt Project file (*.pro)"). Select the file "src.pro" in the 'src'-sub-folder. On the left hand side of the IDE-window you should now be able to see all source-files that are part of QtGrace.
Second step: At the left hand side of the Qt-Creator-window you find some icons. Click on the "Projects"-icon and make sure a suitable path for the Qt-Installation is set at the general section. (You may have to consult the Qt-Manual on some systems on how to do so correctly.) You have two options now: either set the build-path in the general build settings to the 'bin'-subfolder or remember the build path that has been set automatically and copy the executable after the compilation to the 'bin'-subfolder. You will also have to set the destination of the executable to be executed from within Qt Creator in the settings in order to run QtGrace after the compilation from within Qt Creator.
Third step: Click the 'Edit'-icon on the left side. Click on the 'Build All'-Icon (the one with the hammer in the left hand lower corner). This will initiate the process of compilation and may take a while. You may also see a few thousand warnings which can be ignored (hopefully) but there should be no errors (if you get errors, report them to me and I will provide information on how to solve this problem). (Special platform specific notes: see below)
Fourth step: Everything has been compiled now and you should be able to start QtGrace. Either you double-click on the qtgrace icon (or qtgrace.exe) in the bin-folder or you set the execution path in the project settings to this file and run it from within the Qt Creator.
Done! 

On Windows:
You have to set the path to the Qt-dlls in your PATH-variable or copy the dlls to the bin-folder (look for 'QtCore4.dll' and use the path thereof). Otherwise you can only run qtgrace from within the QtCreator. (You need the following dlls: QtCore4.dll, QtGui4.dll, QtNetwork4.dll, mingwm10.dll, libgcc_s_dw2-1.dll; The path where they can be found is usually something like 'C:\Qt\2010.05\qt\bin\'.)

On Linux:
Make sure the environment variables do not contain an entry like LANG=de_DE.UTF-8 (or similar containing UTF-8 and de). In this case either remove this entry (unset LANG or set LANG=C) or set LC_NUMERIC=C (preferred solution).

On Mac OS X:
Executables are organized as disguised folders on such systems. Therefore after compilation in order to work in a MacOS-way you have to open the package-contents of qtgrace (right-click on qtgrace in the 'bin'-folder and select 'show package contents'). Then go to 'Contents'. Copy the contents of the original unzipped folder except the 'bin'-subfolder and the grace-5.1.22.tar.gz into this 'Contents-folder'. Copy the contents (except 'qtgrace') of the 'bin'-subfolder into the 'MacOS'-folder. Now you should be able to execute qtgrace by clicking on qtgrace in the 'bin'-subfolder. It should also be possible to move/copy qtGrace in every folder you like just like any other MacOS-application (put it for example in your Applications-folder). 


Known Problems:

- On systems that have the environment variable "LANG" defined and the value contains 'UTF8' and 'de' (system-language set to german): The Grace/Qt-core of qtgrace has problems interpreting some decimal numbers that contain '.' instead of ',' as decimal separator. In this case you will not be able to display any data since the viewport-coordinates are always invalid. I don't know how to solve this yet. Workaround: unset "LANG" or set "LC_NUMERIC=C" (this overwrites language-settings and always '.' is used as decimal separator). 
- Printing directly to a printer via the native printer-dialog is possible but I have not tested it extensively (but it seem to work in a acceptable way). Most settings are not mirrored in the native dialog. Direct printing without the native printer-dialog is only possible on systems that support the 'lpr' printing command (or any other printer-command like 'kprinter' on some linux-systems) and accept postscript files (i.e. a system command like 'lpr file.ps' will actually print the contents of 'file.ps' on the standard-(line)-printer). Printing to files is always possible. You have to physically print the file-contents via a different/external program (like OpenOffice). 
- On some Linux-systems the scrollbars are not displayed correctly but they still stay usable (I don't know why, yet. Seems to be a Qt-problem…).
- On Windows systems the usage of the internal html-viewer for help-files has been disabled (the option is present, but internally discarded). I had to do this, because the webkit- and phonon-packages of Qt don't seem to work together on Windows. (For developers who want to give it a try: remove the preprocess directives in 'replacement_main.cpp' at lines 1489, 1492, 1494 and 1502.)  


Things that work in Grace, but not in qtGrace:

- I have rewritten the spreadsheet-editor. Therefore it may not work as you are used to it (or maybe you won't even notice).
- I have written a simple text-editor for creating and editing sets. On Unix the default in Grace is to open 'vi' ('Create new->In text editor'). This option is not portable (at least not in a way I would like). I used an internal text-editor because this seems to be comfortable enough (suggestions for improvements are welcome).


Additions to qtGrace (not present in Grace):

- I have included an import-filter for binary data (Grace only supports ascii-files). Usage: see below. There is also a binary export for single sets and the possibility to import such sets later by using the 'grace_binary_format.fmt' for the binary import-filter.
- In all I/O-dialogs I have inserted a button on the upper left hand side (the one with the arrow pointing upwards). Clicking on it will set the current path on the parent-path of the current folder (like clicking on '..').
- In all I/O-dialogs I have inserted a button on the right hand side in the middle of the dialog (the one showing a folder). Clicking on it will open the native file selection dialog of your operating system (This is very useful, because this dialog is more comfortable than the Grace-I/O-dialog in my opinion. You don't have to use it if you don't think so.).
- I inserted an option for ascii-import to use ',' instead of '.' as decimal separator in ascii-files.
- I have inserted a history-menu showing the files you have opened recently.
- The QtGrace-specific settings, the preferences and the history are stored in an ini-file that is read at startup and written when QtGrace is closed. (If you have a wish for a parameter to be restored in every session of QtGrace: let me know and I may insert it in the ini-file.)
- I have inserted another data-transformation-dialog: Data->Transformation->Filters. With this dialog you are able to use low-pass-, high-pass- and band-pass-filters. They are based on fourier-transformations. This dialog is currently in an early stage of development. Not all types of filters will work as expected (Butterworth- and Brickwall-filter should work; you have been warned). The conversion of the x-axis to an axis showing time in seconds is necessary for interpreting the frequency correctly (this conversation is only used internally - your x-axis is not altered). Any suggestions for improvements are welcome! 
- In the properties-dialog I have inserted a button in the bottom right hand corner called 'Extra' opening a separate dialog for the QtGrace-specific settings. (Changing the Grace Home directory will probable not work reliably, this is still in an experimental stage.) As a default, all help-files are displayed in an internal html-viewer. You may also use your favorite html-viewer by setting the path to it in this dialog (you have to set a command that opens your viewer). The drawback is, that not every external html-viewer accepts the html-extension (the part of the html-address after #). You may also set a different language here, but there are no complete translations of the user interface yet (help is welcome here). The show/hide-workaround has been included because on some linux-systems the behavior of Qt is a bit more complicated than on other systems. Paint events are not done completely sometimes (at least not every time or I am doing something wrong). Sometimes using this workaround helps, but not always. This can be very(!) annoying (there has been a time in which I liked linux - about 10 years ago - but the linux-distributions I tried over the last 3 year have all been very disappointing. They tend to have a lot of fancy stuff like window decorations, transparencies and so on, but as far as I am concerned the usability has decreased). I don't have a solution for this so far. Finally in the QtGrace-settings-dialog you can increase or decrease the number of recent files displayed in the 'File' menu. 
- In the print-dialog I inserted a few file-formats for export. I also inserted a button that lets you switch to the native printer-dialog of your operating system. This is still in an early stage of development. I am not sure whether it works on all circumstances (bug-reports, suggestions, wishes are welcome).
- Experimental UnDo/ReDo-feature: see below.


How to use the binary import filter:

To import data from a binary file go to: Data->Import->Binary…
This will open a dialog. Be aware, that you have to know exactly (!) how the structure of the file is that you want to open. You have to tell the import-filter the exact format once and afterwards you may chose to save this format-information to reuse it later. I have included the file-format-specification of wav-files: Click 'Load File Format' and select 'wav_format.fmt' in the bin-folder. To select the actual binary file click on 'Browse…' on the right hand side of 'Datafile:'. By default it is assumed that the binary file also contains a header that has some information about the data present (this is the case for wav-files). 
The first part of telling the filter about the file format is to define the header-contents (byte for byte). This is done by adding a token to the list (click on '+') and tell the filter the format of the token (usually this is the kind of numerical representation of a number in a C-like format). The 'Bytes' box is only used for 'Offset' tokens that are ignored during data import later. It is possible (but not strictly necessary for every file type) to tell the filter how to use the header-information via the ComboBox 'InputAs'. In case you have done something wrong you are able to delete a token by clicking on '-'.
By clicking 'TestLoad'  you can check whether your input has been correct (I always recommend clicking 'TestLoad' since it is needed for some files). The 'File-Info'-tab contains  the data read from the header. 
The second part is setting the Data-Format. It is assumed, that the data is present after the header in the file as a stream of bytes (no additional information in-between). It is also assumed, that the data-points are either present one after the other or one channel after the other. You have to set the format of every channel present in the file and whether or not this channel shall be imported.
The last step is to set the destination for the import: set-type and graph-number. You may only import one data set at a time.
It is also possible for data and header to be present in different files. You may select both of them in this case. For the header-information two versions are supported yet: header-information in binary format or in the format of ini-files (like system settings: '[Data] t0=5 dt=0.1' separated by new lines).
Experiment with binary import on wav-files. This may give you a good idea of how I meant it to work.
Any suggestions for improvements are welcome.


Undo/Redo-function:
Starting with version v0.1.3 I have included a feature to Undo and later Redo some operations the user does with graphs and data sets. It is deactivated as a default because it is of an experimental nature at this point. It will be activated as a default in a later release when I am sure that no harm is done by this function. To activate it: Go to Edit->UndoList and set the "Undo active"-option. This option will be saved in the ini-preference-file and will be restored at every startup of QtGrace (keep this in mind: if you activate Undo/Redo, it will stay active until you deactivate it again!). I do not recommend activating this option for Graphs that include large datasets (>100.000 points) since it may consume a lot of memory because the undo saves up to 100 states of your work.
Since you now have been warned, let us get to the nice stuff: What is possible with this feature?
When "Undo active" is activated, every supported operation is recorded as can be seen in the UndoList. In this list you will find a description of what you have done (the last one is the one on the bottom) and at the beginning of one line the letter 'U' or the letter 'R'. Actions marked as such are the actions that will be Undone or Redone when you use Edit->UnDo or Edit->ReDo respectively. You may also select one or more actions in the list and click on "Undo" below the list. Undo will undo the actions form the last one upwards. Redo will undo the actions from upper most selected action downwards. Every UnDo- or ReDo- operation is considered as some sort of toggle-operation. After an action has been undone a "(*)" will appear at the beginning of the description in the UndoList. This means, that you already have made this undone. Clicking on it and clicking Undo afterwards will effectively redo it. This is also the case, when you use Edit->UnDo. An action that has already been made undone will be redone, when it is reached by the Edit->Undo-operation. Doing a normal operation in QtGrace will set the 'U'-marker to the last operation in the list. This means that by clicking Edit->UnDo the last operation will be made undone and the 'U' will go to the operation before this one. The 'R' for Redo will then be set at the last operation. Clicking multiple times on Edit-UnDo will set the 'U'-marker one operation back(=upwards) until the end of the list is reached or a new normal operation is done in QtGrace. You can always do a manual undo via the list. Manual operations do not alter the 'U'-marker. Using Edit->ReDo will Undo the Undo-operations until the end of the list is reached. Give it a try and you will see what I mean. The shortcuts Ctrl+Z and Ctrl+Shift+Z are used for Undo and Redo. Please note: Ctrl+Z is normally used for Zoom-operations. If Undo is possible, Ctrl+Z will result in an undo; if not, a zoom is initiated.
One further warning: Operations that change the ordering of the sets in a graph or the ordering of graphs (like swap-operations or pack-sets) are a bit dangerous if you do manual undo. At the moment the undo-function does not check whether the set-number has been changed since the operation you want to undo. Doing a chronological undo with Edit->Undo should be save, manual undo can sometime have unexpected results.
Simple description of what Undo/Redo does: Undo does set the state before the action has been performed, Undo again will set the state after the action has been performed. (Undo and Redo are only different with respect to the chronological order in which operations are made undone.) Undo/Redo does usually NOT really do the action again (there are some exceptions), only data is restored. Please use the manual undo-operation only for emergencies or if you really know what you want. Don't manually undo and redo several operations in arbitrary order to often, because unexpected results will be guaranteed. Chronological Undo via Edit->Undo or Edit-Redo is preferred.
Any suggestions are as always very welcome! Bug-reports as well.
Thank you.


Version history:
v0.1.2		initial release on sourceforge.net
-		I made a few silent updates to remove some more or less minor bugs
v0.1.2a		bug-fix-release: major bug in "Arrange graphs"-dialog removed; adjustments on the sliders (especially their resize-behavior); changes in the routine for loading gracerc.user: this file is searched first in the working directory, then in the directory of the executable and last in the users home directory; special-tick-marks-problems solved
v0.1.3		buf-fixes: the transformation between word- and viewport-coordinates has been included in the objects-dialogs (boxes, ellipses …); some of the dialogs have text-lines in which usually numbers are entered (like the start- and stop-values in the axis-dialog), now more of them accept parametric values as well (like the constant PI), this is a feature of Grace that has been temporarily deactivated during the development phase of QtGrace and had overlook to reactivate it, this has now been done; the native-printer-dialog now uses the set page-orientation as a default; 
		Undo/Redo included (partially and experimental; see above)
v0.1.3a		hotfix for a severe memory-bug in the undo-function; undo is still unfinished and experimental
v0.1.4		first release with complete Undo/Redo; several bug-fixes of mostly minor stuff
v0.1.5		several bug fixes and improvements on the repaint-system (which is especially necessary for newer Qt-versions)

Have fun using QtGrace!

Best regards
Andreas Winter (andwin)
 
