premake5 gmake2
cd build

make config=debug
cd Debug
./FullTest

cd ..

make config=release
cd Release
./FullTest

cd ../..