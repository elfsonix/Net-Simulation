cmake_minimum_required(VERSION 3.13)
project(Symulacja_sieci)

set(CMAKE_CXX_STANDARD 14)

add_executable(Symulacja_sieci main.cpp "include/NodeCollection.hpp" "include/Factory.hpp" "include/Worker.hpp" "include/Ramp.hpp" "include/Storehouse.hpp" "include/Package.hpp")