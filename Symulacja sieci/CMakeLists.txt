cmake_minimum_required(VERSION 3.13)
project(Symulacja_sieci)

set(CMAKE_CXX_STANDARD 14)

add_executable(Symulacja_sieci main.cpp "Factory Package/NodeCollection.hpp" "Factory Package/Factory.hpp" "Node Package/Worker.hpp" "Node Package/Ramp.hpp" "Node Package/Storehouse.hpp" "Storage Package/Package.hpp")