cmake_minimum_required(VERSION 3.8)
project(W7)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES w7.cpp Product.cpp Product.h Sale.cpp Sale.h iProduct.h)
add_executable(W7 ${SOURCE_FILES})