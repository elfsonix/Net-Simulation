cmake_minimum_required(VERSION 3.13)
project(Symulacja_sieci)
include_directories(include
        googletest-master/googlemock/include
        googletest-master/googletest/include)
set(CMAKE_CXX_STANDARD 17)
set(TEST_SOURCES
        test/test_package_queue.cpp test/test_receiver.cpp test/main_test.cpp test/test_package_sender.cpp)
set(SOURCE_FILES "src/PackageQueue.cpp" "src/Package.cpp" "src/ReceiverPreferences.cpp" "src/PackageSender.cpp" "src/Storehouse.cpp" )


add_subdirectory(googletest-master)
link_libraries(gmock)

add_executable(Symulacja_sieci main.cpp "include/QueueType.hpp" "include/PackageQueue.hpp" "include/Package.hpp" "include/IPackageStockpile.hpp" "include/IPackageReceiver.hpp" "include/NodeCollection.hpp" "include/Factory.hpp" "include/Worker.hpp" "include/Ramp.hpp" "include/Storehouse.hpp" "include/PackageSender.hpp" "include/ReceiverPreferences.hpp" "include/Simulation.hpp")

add_executable(konfig_run ${SOURCE_FILES} main.cpp)

add_executable(konfig_test ${SOURCE_FILES} ${TEST_SOURCES})



