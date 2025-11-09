#!/usr/bin/env bash

premake5 gmake2
cd build
make config=debug
cd Debug
cd ..
make config=release
cd Release