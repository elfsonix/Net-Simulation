cmake_minimum_required(VERSION 3.13)
project(NetSim)
include_directories(include                     #nasz folder include
        googletest-master/googlemock/include    #foldery google test
        googletest-master/googletest/include)
set(CMAKE_CXX_STANDARD 17)
set(TEST_SOURCES
        test/main_test.cpp test/test_package.cpp test/test_receiver.cpp) #plik z funkcją main() do testów

#dodaje bibliotekę Google Test, kompiluje ją z użyciem CMakeLists.txt z folderu googletest-master
add_subdirectory(googletest-master)
link_libraries(gmock)

<<<<<<< HEAD
add_executable(Symulacja_sieci main.cpp "include/NodeCollection.hpp" "include/Factory.hpp" "include/Worker.hpp" "include/Ramp.hpp" "include/Storehouse.hpp" "include/Package.hpp")
=======
#Tworzy konfigurację o nazwie konfig_run (nazwę możemy dowolnie zmienić)
# do której dołącza plik main.cpp z funkcją main()
add_executable(konfig_run ${SOURCE_FILES} main.cpp)

#Tworzy konfigurację o nazwie konfig_test służącą do uruchamiania testów jednostkowych
add_executable(konfig_test ${SOURCE_FILES} ${TEST_SOURCES})


add_executable(NetSim main.cpp include/IPackageReceiver.hpp include/PackageQueue.hpp include/QueueType.hpp include/IPackageQueue.hpp include/IPackageStockpile.hpp include/Package.hpp include/PackageSender.hpp include/ReceiverPreferences.hpp include/Worker.hpp include/Simulation.hpp src/ReceiverPreferences.cpp src/PackageQueue.cpp src/PackageSender.cpp)
>>>>>>> Kasia-develop
