cmake_minimum_required(VERSION 3.13)

project(Symulacja_sieci)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -Werror -Wpedantic -pedantic-errors)

include_directories(include
        googletest-master/googlemock/include
        googletest-master/googletest/include)

set(SOURCE_FILES
        "src/Factory.cpp"
        "src/Package.cpp"
        "src/PackageQueue.cpp"
        "src/PackageSender.cpp"
        "src/Ramp.cpp"
        "src/ReceiverPreferences.cpp"
        "src/Storehouse.cpp"
        "src/Worker.cpp")

add_executable(Symulacja_sieci main.cpp
        "include/Factory.hpp"
        "include/IPackageQueue.hpp"
        "include/IPackageReceiver.hpp"
        "include/IPackageStockpile.hpp"
        "include/NodeCollection.hpp"
        "include/Package.hpp"
        "include/PackageQueue.hpp"
        "include/PackageSender.hpp"
        "include/QueueType.hpp"
        "include/Ramp.hpp"
        "include/ReceiverPreferences.hpp"
        "include/ReceiverType.hpp"
        "include/Simulation.hpp"
        "include/Storehouse.hpp"
        "include/Worker.hpp"
        )

add_executable(Symulacja_sieci_debug ${SOURCE_FILES} main.cpp)

set(SOURCES_FILES_TESTS
        test/main_test.cpp
        test/test_factory.cpp
        test/test_node_collection.cpp
        test/test_package.cpp
        test/test_package_queue.cpp
        test/test_ramp.cpp
        test/test_receiver.cpp
        test/test_storehouse.cpp
        test/test_worker.cpp )

add_executable(Symulacja_sieci_test ${SOURCE_FILES} ${SOURCES_FILES_TESTS} test/main_test.cpp)

target_include_directories(Symulacja_sieci_test PUBLIC
        googletest-master/googlemock/include
        googletest-master/googletest/include
        mocks)

add_subdirectory(googletest-master)
target_link_libraries(Symulacja_sieci_test gmock)

