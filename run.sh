cd source
rm -rf build
premake5 gmake2
cd build
make -j6
cd Debug
ls

cd ../../..
cd tests
rm -rf build
premake5 gmake2
cd build
make -j6
cd Debug
./FullTest
cd ../../..