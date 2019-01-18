// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Sonia on 2019-01-11.
//

#include "gtest/gtest.h"
#include "Ramp.hpp"
#include "Worker.hpp"
#include "Storehouse.hpp"

TEST(Ramp, GeneratePackageInTimeTrue){
    std::vector<IPackageReceiver*> receivers;
    std::function<double()> function = ([](){return 0.8;});
    ReceiverPreferences myPref = ReceiverPreferences(receivers, function);
    std::deque<Package> queue;
    Worker myWorker = Worker(1,1, std::make_unique<PackageQueue>(QueueType::FIFO, queue), myPref);

    std::vector<IPackageReceiver*> receiversR;
    receiversR.push_back(&myWorker);
    std::function<double()> functionR = ([](){return 0.8;});
    Ramp myRamp = Ramp(1, 2, ReceiverPreferences(receiversR, functionR));
    Time time = 4;
    myRamp.generatePackage(time);
    EXPECT_TRUE(myRamp.returnBufferState());
}

TEST(Ramp, GeneratePackageInTimeFalse){
    std::vector<IPackageReceiver*> receivers;
    std::function<double()> function = ([](){return 0.8;});
    Ramp myRamp = Ramp(1, 2, ReceiverPreferences(receivers, function));
    Time time = 3;
    myRamp.generatePackage(time);
    EXPECT_FALSE(myRamp.returnBufferState());
}

TEST(Ramp, isProductSentToBuffer){
    std::vector<IPackageReceiver*> receivers;
    std::function<double()> function = ([](){return 0.8;});
    std::deque<Package> queue1;
    PackageQueue packageQueueLIFO = PackageQueue(QueueType::LIFO, queue1);
    Storehouse storehouse1 = Storehouse(3, std::make_unique<PackageQueue>(packageQueueLIFO));
    receivers.push_back(&storehouse1);

    ReceiverPreferences myPref = ReceiverPreferences(receivers, function);
    Ramp myRamp = Ramp(1, 3, myPref);
    myRamp.generatePackage(3);
    EXPECT_TRUE(myRamp.returnBufferState());
}
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)