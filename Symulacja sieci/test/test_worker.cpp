// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Sonia on 2019-01-11.
//
#include "gtest/gtest.h"
#include "Worker.hpp"

TEST(Worker, receiveProduct){
    //Przygotowanie środowiska
    Package myPackage = Package();
    std::vector<IPackageReceiver*> receivers;
    std::function<double()> function = ([](){return 1;});
    ReceiverPreferences myPref = ReceiverPreferences(receivers, function);
    std::deque<Package> queue;
    Worker myWorker = Worker(1,1, std::make_unique<PackageQueue>(QueueType::FIFO, queue), myPref);
    //Test
    myWorker.receivePackage(myPackage);
    EXPECT_EQ(myPackage.getID(), myWorker.popPackage().getID());
}

TEST(Worker, isProductionTimeRight){
    Package myPackage = Package();
    for(int i = 1; i<4; i++){
        std::vector<IPackageReceiver*> receivers;
        std::function<double()> function = ([](){return 1;});
        ReceiverPreferences myPref = ReceiverPreferences(receivers, function);
        std::deque<Package> queue;
        Worker myWorker = Worker(i,i, std::make_unique<PackageQueue>(QueueType::FIFO, queue), myPref);
        myWorker.receivePackage(Package());
        for (int j = 1; j<=i; j++){
            myWorker.processPackage();
        }
        EXPECT_FALSE(myWorker._bufferOfProcessedPackage.has_value());
    }
}

TEST(Worker, isProductPassedForward){
    Package myPackage = Package();

    std::vector<IPackageReceiver*> receivers1;
    std::function<double()> function = ([](){return 1;});
    ReceiverPreferences myPref1 = ReceiverPreferences(receivers1, function);
    std::deque<Package> queue1;
    Worker worker1 = Worker(1,1, std::make_unique<PackageQueue>(QueueType::FIFO, queue1), myPref1);

    std::vector<IPackageReceiver*> receivers2;
    receivers2.push_back(&worker1);
    std::function<double()> function2 = ([](){return 1;});
    ReceiverPreferences myPref2 = ReceiverPreferences(receivers2, function2);
    std::deque<Package> queue2;
    Worker worker2 = Worker(2,1, std::make_unique<PackageQueue>(QueueType::FIFO, queue2), myPref2);

    worker2.receivePackage(myPackage);
    worker2.processPackage();
    EXPECT_EQ(myPackage.getID(), worker1.popPackage().getID());
}
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)