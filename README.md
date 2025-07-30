# StackSmashing

## Table of Contents
- [Introduction](#introduction)
- [Build and Run](#build-and-run)
- [Possible Output](#possible-output)
- [How does this work](#how-does-this-work)

## Introduction
The purpose of this project is to demonstrate how buffer overflow can hijack the control flow.

The project is Linux only currently.

## Build and Run
To clone and run this project, you'll need [Git](https://git-scm.com), [CMake](https://cmake.org/), GDB and [Python](https://python.org) installed on your computer. From your command line:

```bash
# Clone this repository
$ git clone https://github.com/Hayk10002/StackSmashing

# Go into the repository
$ cd StackSmashing

# Generate the build files
$ cmake -DCMAKE_BUILD_TYPE=Release -S . -B build

# Build the project
$ cmake --build build --config Release
```

Then, run the `run.sh` file. 

To see a working example, see the latest run in [Github Actions](https://github.com/Hayk10002/StackSmashing/actions) for this project.

## How does this work
`run.sh` installs python libraries needed for this project, then runs a python script, which does these things.

1. Runs the vulnerable executable with gdb and extracts a valueable information about the executable, the offset which can be used to overwrite the return pointer of a function.
1. Then, runs the executable again, captures the leaked address of the function to which the control flow will be forwarded to, and then using the offset, actually overwrites the return pointer of a function to the leaked one, successfully hijacking the control flow.

Tests also will show that turning stack canaries on will prevent this exploit.
