# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Kasia\Documents\GitHub\agh_air_inf2_2018_netsim__4b_4\Symulacja sieci"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Kasia\Documents\GitHub\agh_air_inf2_2018_netsim__4b_4\Symulacja sieci\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/konfig_run.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/konfig_run.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/konfig_run.dir/flags.make

CMakeFiles/konfig_run.dir/main.cpp.obj: CMakeFiles/konfig_run.dir/flags.make
CMakeFiles/konfig_run.dir/main.cpp.obj: CMakeFiles/konfig_run.dir/includes_CXX.rsp
CMakeFiles/konfig_run.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Kasia\Documents\GitHub\agh_air_inf2_2018_netsim__4b_4\Symulacja sieci\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/konfig_run.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\konfig_run.dir\main.cpp.obj -c "C:\Users\Kasia\Documents\GitHub\agh_air_inf2_2018_netsim__4b_4\Symulacja sieci\main.cpp"

CMakeFiles/konfig_run.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/konfig_run.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Kasia\Documents\GitHub\agh_air_inf2_2018_netsim__4b_4\Symulacja sieci\main.cpp" > CMakeFiles\konfig_run.dir\main.cpp.i

CMakeFiles/konfig_run.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/konfig_run.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Kasia\Documents\GitHub\agh_air_inf2_2018_netsim__4b_4\Symulacja sieci\main.cpp" -o CMakeFiles\konfig_run.dir\main.cpp.s

# Object files for target konfig_run
konfig_run_OBJECTS = \
"CMakeFiles/konfig_run.dir/main.cpp.obj"

# External object files for target konfig_run
konfig_run_EXTERNAL_OBJECTS =

konfig_run.exe: CMakeFiles/konfig_run.dir/main.cpp.obj
konfig_run.exe: CMakeFiles/konfig_run.dir/build.make
konfig_run.exe: googletest-master/googlemock/libgmockd.a
konfig_run.exe: googletest-master/googlemock/gtest/libgtestd.a
konfig_run.exe: CMakeFiles/konfig_run.dir/linklibs.rsp
konfig_run.exe: CMakeFiles/konfig_run.dir/objects1.rsp
konfig_run.exe: CMakeFiles/konfig_run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Kasia\Documents\GitHub\agh_air_inf2_2018_netsim__4b_4\Symulacja sieci\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable konfig_run.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\konfig_run.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/konfig_run.dir/build: konfig_run.exe

.PHONY : CMakeFiles/konfig_run.dir/build

CMakeFiles/konfig_run.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\konfig_run.dir\cmake_clean.cmake
.PHONY : CMakeFiles/konfig_run.dir/clean

CMakeFiles/konfig_run.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Kasia\Documents\GitHub\agh_air_inf2_2018_netsim__4b_4\Symulacja sieci" "C:\Users\Kasia\Documents\GitHub\agh_air_inf2_2018_netsim__4b_4\Symulacja sieci" "C:\Users\Kasia\Documents\GitHub\agh_air_inf2_2018_netsim__4b_4\Symulacja sieci\cmake-build-debug" "C:\Users\Kasia\Documents\GitHub\agh_air_inf2_2018_netsim__4b_4\Symulacja sieci\cmake-build-debug" "C:\Users\Kasia\Documents\GitHub\agh_air_inf2_2018_netsim__4b_4\Symulacja sieci\cmake-build-debug\CMakeFiles\konfig_run.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/konfig_run.dir/depend

