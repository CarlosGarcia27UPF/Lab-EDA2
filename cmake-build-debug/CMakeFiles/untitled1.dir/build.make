# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.1.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.1.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\juget\CLionProjects\Lab-EDA2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\juget\CLionProjects\Lab-EDA2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/untitled1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/untitled1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled1.dir/flags.make

CMakeFiles/untitled1.dir/main.c.obj: CMakeFiles/untitled1.dir/flags.make
CMakeFiles/untitled1.dir/main.c.obj: C:/Users/juget/CLionProjects/Lab-EDA2/main.c
CMakeFiles/untitled1.dir/main.c.obj: CMakeFiles/untitled1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\juget\CLionProjects\Lab-EDA2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/untitled1.dir/main.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/untitled1.dir/main.c.obj -MF CMakeFiles\untitled1.dir\main.c.obj.d -o CMakeFiles\untitled1.dir\main.c.obj -c C:\Users\juget\CLionProjects\Lab-EDA2\main.c

CMakeFiles/untitled1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled1.dir/main.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\juget\CLionProjects\Lab-EDA2\main.c > CMakeFiles\untitled1.dir\main.c.i

CMakeFiles/untitled1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled1.dir/main.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\juget\CLionProjects\Lab-EDA2\main.c -o CMakeFiles\untitled1.dir\main.c.s

CMakeFiles/untitled1.dir/utilities.c.obj: CMakeFiles/untitled1.dir/flags.make
CMakeFiles/untitled1.dir/utilities.c.obj: C:/Users/juget/CLionProjects/Lab-EDA2/utilities.c
CMakeFiles/untitled1.dir/utilities.c.obj: CMakeFiles/untitled1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\juget\CLionProjects\Lab-EDA2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/untitled1.dir/utilities.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/untitled1.dir/utilities.c.obj -MF CMakeFiles\untitled1.dir\utilities.c.obj.d -o CMakeFiles\untitled1.dir\utilities.c.obj -c C:\Users\juget\CLionProjects\Lab-EDA2\utilities.c

CMakeFiles/untitled1.dir/utilities.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled1.dir/utilities.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\juget\CLionProjects\Lab-EDA2\utilities.c > CMakeFiles\untitled1.dir\utilities.c.i

CMakeFiles/untitled1.dir/utilities.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled1.dir/utilities.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\juget\CLionProjects\Lab-EDA2\utilities.c -o CMakeFiles\untitled1.dir\utilities.c.s

CMakeFiles/untitled1.dir/user.c.obj: CMakeFiles/untitled1.dir/flags.make
CMakeFiles/untitled1.dir/user.c.obj: C:/Users/juget/CLionProjects/Lab-EDA2/user.c
CMakeFiles/untitled1.dir/user.c.obj: CMakeFiles/untitled1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\juget\CLionProjects\Lab-EDA2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/untitled1.dir/user.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/untitled1.dir/user.c.obj -MF CMakeFiles\untitled1.dir\user.c.obj.d -o CMakeFiles\untitled1.dir\user.c.obj -c C:\Users\juget\CLionProjects\Lab-EDA2\user.c

CMakeFiles/untitled1.dir/user.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled1.dir/user.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\juget\CLionProjects\Lab-EDA2\user.c > CMakeFiles\untitled1.dir\user.c.i

CMakeFiles/untitled1.dir/user.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled1.dir/user.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\juget\CLionProjects\Lab-EDA2\user.c -o CMakeFiles\untitled1.dir\user.c.s

CMakeFiles/untitled1.dir/menu.c.obj: CMakeFiles/untitled1.dir/flags.make
CMakeFiles/untitled1.dir/menu.c.obj: C:/Users/juget/CLionProjects/Lab-EDA2/menu.c
CMakeFiles/untitled1.dir/menu.c.obj: CMakeFiles/untitled1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\juget\CLionProjects\Lab-EDA2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/untitled1.dir/menu.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/untitled1.dir/menu.c.obj -MF CMakeFiles\untitled1.dir\menu.c.obj.d -o CMakeFiles\untitled1.dir\menu.c.obj -c C:\Users\juget\CLionProjects\Lab-EDA2\menu.c

CMakeFiles/untitled1.dir/menu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled1.dir/menu.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\juget\CLionProjects\Lab-EDA2\menu.c > CMakeFiles\untitled1.dir\menu.c.i

CMakeFiles/untitled1.dir/menu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled1.dir/menu.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\juget\CLionProjects\Lab-EDA2\menu.c -o CMakeFiles\untitled1.dir\menu.c.s

# Object files for target untitled1
untitled1_OBJECTS = \
"CMakeFiles/untitled1.dir/main.c.obj" \
"CMakeFiles/untitled1.dir/utilities.c.obj" \
"CMakeFiles/untitled1.dir/user.c.obj" \
"CMakeFiles/untitled1.dir/menu.c.obj"

# External object files for target untitled1
untitled1_EXTERNAL_OBJECTS =

untitled1.exe: CMakeFiles/untitled1.dir/main.c.obj
untitled1.exe: CMakeFiles/untitled1.dir/utilities.c.obj
untitled1.exe: CMakeFiles/untitled1.dir/user.c.obj
untitled1.exe: CMakeFiles/untitled1.dir/menu.c.obj
untitled1.exe: CMakeFiles/untitled1.dir/build.make
untitled1.exe: CMakeFiles/untitled1.dir/linkLibs.rsp
untitled1.exe: CMakeFiles/untitled1.dir/objects1
untitled1.exe: CMakeFiles/untitled1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\juget\CLionProjects\Lab-EDA2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable untitled1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\untitled1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled1.dir/build: untitled1.exe
.PHONY : CMakeFiles/untitled1.dir/build

CMakeFiles/untitled1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\untitled1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/untitled1.dir/clean

CMakeFiles/untitled1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\juget\CLionProjects\Lab-EDA2 C:\Users\juget\CLionProjects\Lab-EDA2 C:\Users\juget\CLionProjects\Lab-EDA2\cmake-build-debug C:\Users\juget\CLionProjects\Lab-EDA2\cmake-build-debug C:\Users\juget\CLionProjects\Lab-EDA2\cmake-build-debug\CMakeFiles\untitled1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/untitled1.dir/depend

