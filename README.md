# test_radio

## Build instructions

### Windows (MSYS2 MinGW64)

git clone https://github.com/stanislav539261/test_radio --recurse-submodules</br>
mkdir -p test_radio/build</br>
cd test_radio/build</br>
cmake -G "MinGW Makefiles" ..</br>
mingw32-make -j NUM_THREADS</br>