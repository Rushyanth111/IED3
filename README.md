# IED3

Currently working on an ID3 editor. Is currently only focused on the v1.1 version of the tag version. 

To do:

1. Solidify and include the argument passing gaurds.
2. Begin work on the ID3 class to parse information.
3. Edit the ID3 tags on an MP3 and save.
4. Work on Id3 v3.
5. Work with available audioplayback library to add playback functionality.
6. Use GUI to consolidate the process.

... and lots more to do.

This build is made using Cmake, the minimum version can be found in CMakeLists.txt

___

The developmental tools used are:

1. GNU's GCC Compiler Collection.[May Change to Clang in the future for building with reliable toolchain.]
2. GNU's MAKE toolchain.
3. CMAKE build system.
4. Git for handling Github requests.
5. VSCode as a Text Editor.

___

To build it you need CMAKE and GCC present on the system. Execute the following commands in the directory to build it:

```bash
git clone git@github:Rushyanth111/IED3.git
mkdir build
cd build
cmake -G "MinGW Makefiles".. -CMAKE_SH="CMAKE_NOT_FOUND"
mingw-make32.exe
```

This will start the building process. Please be patient. 

___
Note: This project is not in the lieu of professional development. This is a hobby to learn programming. 