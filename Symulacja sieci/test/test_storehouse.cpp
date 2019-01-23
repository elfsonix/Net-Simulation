// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Sonia on 2019-01-11.
//
#include "gtest/gtest.h"
#include "Storehouse.hpp"

TEST(Storehouse, isProductReceived){
    Package myPackage = Package();
    std::deque<Package> packageQueue;
    Storehouse myStorehouse = Storehouse(1, std::make_unique<PackageQueue>(QueueType::FIFO, packageQueue));
    myStorehouse.receivePackage(myPackage);
    EXPECT_EQ(myPackage.getID(), myStorehouse.begin()->getID());
}
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)