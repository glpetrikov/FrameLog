premake5 gmake2
cd build

make config=debug
cd Debug
./HelloFrameLog
./FileExample
./SimpleExample

cd ..

make config=release
cd Release
./HelloFrameLog
./FileExample
./SimpleExample

cd ../..