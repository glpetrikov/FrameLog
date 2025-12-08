#!/bin/bash
premake5 gmake2
cd build
make clean && make config=release
cd Release
ls
./FileHandler
./FileHandler2
cd ../../..
