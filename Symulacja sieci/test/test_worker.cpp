//
// Created by Sonia on 2019-01-11.
//
#include "gtest/gtest.h"
#include "Worker.hpp"
/*
TEST(Worker, receiveProduct){
    //Przygotowanie środowiska
    Package myPackage = Package();
    std::vector<IPackageReceiver*> receivers;
    std::function<std::vector<double>()> drawnNumberVector = std::function<std::vector<double>()>([](){return std::vector<double> {1};});
    ReceiverPreferences myPref = ReceiverPreferences(receivers, drawnNumberVector);
    std::deque<Package> queue;
    Worker myWorker = Worker(1,1, std::make_unique<PackageQueue>(QueueType::FIFO, queue), myPref);
    //Test
    myWorker.receivePackage(myPackage);
    EXPECT_EQ(myPackage.getID(), myWorker.popPackage().getID());
}

TEST(Worker, isProductionTimeRight){
    Package myPackage = Package();
    for(int i = 1; i<4; i++){
        int testTime = i;
        Worker myWorker = Worker(i,i,std::make_unique<PackageQueue>(QueueType::FIFO, std::deque<Package> queue));
        myWorker.receivePackage(Package());
        for (int j = 1; j<=i; j++){
            myWorker.processPackage();
        }
        EXPECT_FALSE(myWorker._bufferOfProcessedPackage.has_value());
    }
}

TEST(Worker, isProductPassedForward){
    Package myPackage = Package();
    Worker worker1 = Worker(1,1,std::make_unique<PackageQueue>(QueueType::FIFO, std::deque<Package> queue),);
    Worker worker2 = Worker(2,1,std::make_unique<PackageQueue>(QueueType::FIFO, std::deque<Package> queue),);

    worker1.receivePackage(myPackage);
    worker1.processPackage();
    EXPECT_EQ(myPackage.getID(), worker2.popPackage().getID());
}*/