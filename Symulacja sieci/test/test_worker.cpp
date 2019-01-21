// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Sonia on 2019-01-11.
//
#include "gtest/gtest.h"
#include "Worker.hpp"
#include "Storehouse.hpp"

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
    EXPECT_EQ(myPackage.getID(), myWorker.begin()->getID());
}

TEST(Worker, isProductionTimeRight1){
    std::vector<IPackageReceiver*> receivers;
    std::deque<Package> queue1;
    std::deque<Package> queue2;
    std::deque<Package> queue3;

    PackageQueue packageQueueLIFO = PackageQueue(QueueType::LIFO, queue1);
    PackageQueue packageQueueFIFO = PackageQueue(QueueType::FIFO, queue2);
    PackageQueue workerQueue = PackageQueue(QueueType::FIFO, queue3);

    Storehouse storehouse1 = Storehouse(3, std::make_unique<PackageQueue>(packageQueueLIFO));
    Storehouse storehouse2 = Storehouse(4, std::make_unique<PackageQueue>(packageQueueFIFO));

    receivers.push_back(&storehouse1);
    receivers.push_back(&storehouse2);
    std::function<double()> function = ([](){return 0.8;});
    ReceiverPreferences myPref = ReceiverPreferences(receivers, function);

    Worker myWorker = Worker(1, 2, std::make_unique<PackageQueue>(workerQueue),myPref);
    myWorker.receivePackage(Package());
    myWorker.processPackage();
    EXPECT_TRUE(myWorker._bufferOfProcessedPackage.has_value());
}

TEST(Worker, isProductionTimeRight2){
    std::vector<IPackageReceiver*> receivers;
    std::deque<Package> queue1;
    std::deque<Package> queue2;
    std::deque<Package> queue3;

    PackageQueue packageQueueLIFO = PackageQueue(QueueType::LIFO, queue1);
    PackageQueue packageQueueFIFO = PackageQueue(QueueType::FIFO, queue2);
    PackageQueue workerQueue = PackageQueue(QueueType::FIFO, queue3);

    Storehouse storehouse1 = Storehouse(3, std::make_unique<PackageQueue>(packageQueueLIFO));
    Storehouse storehouse2 = Storehouse(4, std::make_unique<PackageQueue>(packageQueueFIFO));

    receivers.push_back(&storehouse1);
    receivers.push_back(&storehouse2);
    std::function<double()> function = ([](){return 0.8;});
    ReceiverPreferences myPref = ReceiverPreferences(receivers, function);

    Worker myWorker = Worker(1, 2, std::make_unique<PackageQueue>(workerQueue),myPref);
    myWorker.receivePackage(Package());
    myWorker.processPackage();
    myWorker.processPackage();
    EXPECT_FALSE(myWorker._bufferOfProcessedPackage.has_value());
}

TEST(Worker, isProductPassedForward){   //dziwne id paczki zwraca
    Package myPackage = Package();

    std::vector<IPackageReceiver*> receivers1;
    std::vector<IPackageReceiver*> receivers2;
    std::deque<Package> queue1;
    std::deque<Package> queue2;
    std::deque<Package> queue3;
    PackageQueue packageQueueLIFO = PackageQueue(QueueType::LIFO, queue1);
    PackageQueue workerQueue1 = PackageQueue(QueueType::FIFO, queue2);
    PackageQueue workerQueue2 = PackageQueue(QueueType::FIFO, queue3);

    Storehouse storehouse1 = Storehouse(3, std::make_unique<PackageQueue>(packageQueueLIFO));
    receivers1.push_back(&storehouse1);

    std::function<double()> function1 = ([](){return 0.8;});
    std::function<double()> function2 = ([](){return 0.8;});
    ReceiverPreferences myPref1 = ReceiverPreferences(receivers1, function1);

    Worker myWorker1 = Worker(1, 1, std::make_unique<PackageQueue>(workerQueue1),myPref1);
    receivers2.push_back(&myWorker1);
    ReceiverPreferences myPref2 = ReceiverPreferences(receivers2, function2);
    Worker myWorker2 = Worker(2, 1, std::make_unique<PackageQueue>(workerQueue2), myPref2);
    myWorker2.receivePackage(myPackage);
    //myWorker2.processPackage();

    EXPECT_EQ(myPackage.getID(), myWorker2.begin()->getID());
}
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)