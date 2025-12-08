set -e

mkdir -p "build"

premake5 gmake2
cd build
make -j6
cd Debug
./FullTest