# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\psyq\projects\simple_ps1_games

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\psyq\projects\simple_ps1_games\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\simple_ps1_games.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\simple_ps1_games.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\simple_ps1_games.dir\flags.make

CMakeFiles\simple_ps1_games.dir\src\games\tic_tac_toe_game.c.obj: CMakeFiles\simple_ps1_games.dir\flags.make
CMakeFiles\simple_ps1_games.dir\src\games\tic_tac_toe_game.c.obj: ..\src\games\tic_tac_toe_game.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\psyq\projects\simple_ps1_games\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/simple_ps1_games.dir/src/games/tic_tac_toe_game.c.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\simple_ps1_games.dir\src\games\tic_tac_toe_game.c.obj /FdCMakeFiles\simple_ps1_games.dir\ /FS -c C:\psyq\projects\simple_ps1_games\src\games\tic_tac_toe_game.c
<<

CMakeFiles\simple_ps1_games.dir\src\games\tic_tac_toe_game.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simple_ps1_games.dir/src/games/tic_tac_toe_game.c.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\simple_ps1_games.dir\src\games\tic_tac_toe_game.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\psyq\projects\simple_ps1_games\src\games\tic_tac_toe_game.c
<<

CMakeFiles\simple_ps1_games.dir\src\games\tic_tac_toe_game.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simple_ps1_games.dir/src/games/tic_tac_toe_game.c.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\simple_ps1_games.dir\src\games\tic_tac_toe_game.c.s /c C:\psyq\projects\simple_ps1_games\src\games\tic_tac_toe_game.c
<<

CMakeFiles\simple_ps1_games.dir\src\games\tic_tac_screen.c.obj: CMakeFiles\simple_ps1_games.dir\flags.make
CMakeFiles\simple_ps1_games.dir\src\games\tic_tac_screen.c.obj: ..\src\games\tic_tac_screen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\psyq\projects\simple_ps1_games\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/simple_ps1_games.dir/src/games/tic_tac_screen.c.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\simple_ps1_games.dir\src\games\tic_tac_screen.c.obj /FdCMakeFiles\simple_ps1_games.dir\ /FS -c C:\psyq\projects\simple_ps1_games\src\games\tic_tac_screen.c
<<

CMakeFiles\simple_ps1_games.dir\src\games\tic_tac_screen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simple_ps1_games.dir/src/games/tic_tac_screen.c.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\simple_ps1_games.dir\src\games\tic_tac_screen.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\psyq\projects\simple_ps1_games\src\games\tic_tac_screen.c
<<

CMakeFiles\simple_ps1_games.dir\src\games\tic_tac_screen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simple_ps1_games.dir/src/games/tic_tac_screen.c.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\simple_ps1_games.dir\src\games\tic_tac_screen.c.s /c C:\psyq\projects\simple_ps1_games\src\games\tic_tac_screen.c
<<

CMakeFiles\simple_ps1_games.dir\src\controller.c.obj: CMakeFiles\simple_ps1_games.dir\flags.make
CMakeFiles\simple_ps1_games.dir\src\controller.c.obj: ..\src\controller.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\psyq\projects\simple_ps1_games\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/simple_ps1_games.dir/src/controller.c.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\simple_ps1_games.dir\src\controller.c.obj /FdCMakeFiles\simple_ps1_games.dir\ /FS -c C:\psyq\projects\simple_ps1_games\src\controller.c
<<

CMakeFiles\simple_ps1_games.dir\src\controller.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simple_ps1_games.dir/src/controller.c.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\simple_ps1_games.dir\src\controller.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\psyq\projects\simple_ps1_games\src\controller.c
<<

CMakeFiles\simple_ps1_games.dir\src\controller.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simple_ps1_games.dir/src/controller.c.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\simple_ps1_games.dir\src\controller.c.s /c C:\psyq\projects\simple_ps1_games\src\controller.c
<<

CMakeFiles\simple_ps1_games.dir\src\core.c.obj: CMakeFiles\simple_ps1_games.dir\flags.make
CMakeFiles\simple_ps1_games.dir\src\core.c.obj: ..\src\core.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\psyq\projects\simple_ps1_games\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/simple_ps1_games.dir/src/core.c.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\simple_ps1_games.dir\src\core.c.obj /FdCMakeFiles\simple_ps1_games.dir\ /FS -c C:\psyq\projects\simple_ps1_games\src\core.c
<<

CMakeFiles\simple_ps1_games.dir\src\core.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simple_ps1_games.dir/src/core.c.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\simple_ps1_games.dir\src\core.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\psyq\projects\simple_ps1_games\src\core.c
<<

CMakeFiles\simple_ps1_games.dir\src\core.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simple_ps1_games.dir/src/core.c.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\simple_ps1_games.dir\src\core.c.s /c C:\psyq\projects\simple_ps1_games\src\core.c
<<

CMakeFiles\simple_ps1_games.dir\src\engine.c.obj: CMakeFiles\simple_ps1_games.dir\flags.make
CMakeFiles\simple_ps1_games.dir\src\engine.c.obj: ..\src\engine.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\psyq\projects\simple_ps1_games\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/simple_ps1_games.dir/src/engine.c.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\simple_ps1_games.dir\src\engine.c.obj /FdCMakeFiles\simple_ps1_games.dir\ /FS -c C:\psyq\projects\simple_ps1_games\src\engine.c
<<

CMakeFiles\simple_ps1_games.dir\src\engine.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simple_ps1_games.dir/src/engine.c.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\simple_ps1_games.dir\src\engine.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\psyq\projects\simple_ps1_games\src\engine.c
<<

CMakeFiles\simple_ps1_games.dir\src\engine.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simple_ps1_games.dir/src/engine.c.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\simple_ps1_games.dir\src\engine.c.s /c C:\psyq\projects\simple_ps1_games\src\engine.c
<<

CMakeFiles\simple_ps1_games.dir\src\main.c.obj: CMakeFiles\simple_ps1_games.dir\flags.make
CMakeFiles\simple_ps1_games.dir\src\main.c.obj: ..\src\main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\psyq\projects\simple_ps1_games\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/simple_ps1_games.dir/src/main.c.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\simple_ps1_games.dir\src\main.c.obj /FdCMakeFiles\simple_ps1_games.dir\ /FS -c C:\psyq\projects\simple_ps1_games\src\main.c
<<

CMakeFiles\simple_ps1_games.dir\src\main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simple_ps1_games.dir/src/main.c.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\simple_ps1_games.dir\src\main.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\psyq\projects\simple_ps1_games\src\main.c
<<

CMakeFiles\simple_ps1_games.dir\src\main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simple_ps1_games.dir/src/main.c.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\simple_ps1_games.dir\src\main.c.s /c C:\psyq\projects\simple_ps1_games\src\main.c
<<

CMakeFiles\simple_ps1_games.dir\src\screen_selector.c.obj: CMakeFiles\simple_ps1_games.dir\flags.make
CMakeFiles\simple_ps1_games.dir\src\screen_selector.c.obj: ..\src\screen_selector.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\psyq\projects\simple_ps1_games\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/simple_ps1_games.dir/src/screen_selector.c.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\simple_ps1_games.dir\src\screen_selector.c.obj /FdCMakeFiles\simple_ps1_games.dir\ /FS -c C:\psyq\projects\simple_ps1_games\src\screen_selector.c
<<

CMakeFiles\simple_ps1_games.dir\src\screen_selector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simple_ps1_games.dir/src/screen_selector.c.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\simple_ps1_games.dir\src\screen_selector.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\psyq\projects\simple_ps1_games\src\screen_selector.c
<<

CMakeFiles\simple_ps1_games.dir\src\screen_selector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simple_ps1_games.dir/src/screen_selector.c.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\simple_ps1_games.dir\src\screen_selector.c.s /c C:\psyq\projects\simple_ps1_games\src\screen_selector.c
<<

# Object files for target simple_ps1_games
simple_ps1_games_OBJECTS = \
"CMakeFiles\simple_ps1_games.dir\src\games\tic_tac_toe_game.c.obj" \
"CMakeFiles\simple_ps1_games.dir\src\games\tic_tac_screen.c.obj" \
"CMakeFiles\simple_ps1_games.dir\src\controller.c.obj" \
"CMakeFiles\simple_ps1_games.dir\src\core.c.obj" \
"CMakeFiles\simple_ps1_games.dir\src\engine.c.obj" \
"CMakeFiles\simple_ps1_games.dir\src\main.c.obj" \
"CMakeFiles\simple_ps1_games.dir\src\screen_selector.c.obj"

# External object files for target simple_ps1_games
simple_ps1_games_EXTERNAL_OBJECTS =

simple_ps1_games.exe: CMakeFiles\simple_ps1_games.dir\src\games\tic_tac_toe_game.c.obj
simple_ps1_games.exe: CMakeFiles\simple_ps1_games.dir\src\games\tic_tac_screen.c.obj
simple_ps1_games.exe: CMakeFiles\simple_ps1_games.dir\src\controller.c.obj
simple_ps1_games.exe: CMakeFiles\simple_ps1_games.dir\src\core.c.obj
simple_ps1_games.exe: CMakeFiles\simple_ps1_games.dir\src\engine.c.obj
simple_ps1_games.exe: CMakeFiles\simple_ps1_games.dir\src\main.c.obj
simple_ps1_games.exe: CMakeFiles\simple_ps1_games.dir\src\screen_selector.c.obj
simple_ps1_games.exe: CMakeFiles\simple_ps1_games.dir\build.make
simple_ps1_games.exe: CMakeFiles\simple_ps1_games.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\psyq\projects\simple_ps1_games\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable simple_ps1_games.exe"
	"C:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\simple_ps1_games.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\simple_ps1_games.dir\objects1.rsp @<<
 /out:simple_ps1_games.exe /implib:simple_ps1_games.lib /pdb:C:\psyq\projects\simple_ps1_games\cmake-build-debug\simple_ps1_games.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\simple_ps1_games.dir\build: simple_ps1_games.exe

.PHONY : CMakeFiles\simple_ps1_games.dir\build

CMakeFiles\simple_ps1_games.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\simple_ps1_games.dir\cmake_clean.cmake
.PHONY : CMakeFiles\simple_ps1_games.dir\clean

CMakeFiles\simple_ps1_games.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\psyq\projects\simple_ps1_games C:\psyq\projects\simple_ps1_games C:\psyq\projects\simple_ps1_games\cmake-build-debug C:\psyq\projects\simple_ps1_games\cmake-build-debug C:\psyq\projects\simple_ps1_games\cmake-build-debug\CMakeFiles\simple_ps1_games.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\simple_ps1_games.dir\depend

