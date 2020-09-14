# This toolchain adds -m32 to compiler flags
# It is required to make CMake link with proper 32-bit libraries

set( CMAKE_SYSTEM_NAME Linux )

set( CMAKE_C_COMPILER clang -m32 )
set( CMAKE_CXX_COMPILER clang++ -m32) 
