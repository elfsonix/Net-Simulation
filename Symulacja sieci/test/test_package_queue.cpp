//
// Created by Kasia on 2018-12-31.
//

#include "gtest/gtest.h"
#include "PackageQueue.hpp"
#include "Package.hpp"
/*
TEST(PackageQueue, isQueueTypeRight){
    Package pack1 = Package();
    Package pack2 = Package();
    std::deque<Package> que;
    que.push_back(pack1);
    que.push_back(pack2);
    PackageQueue packageQueueLIFO = PackageQueue(QueueType::LIFO, que);
    PackageQueue packageQueueFIFO = PackageQueue(QueueType::FIFO, que);
    ASSERT_EQ(QueueType::FIFO, packageQueueFIFO.returnQueueType());
    ASSERT_EQ(QueueType::LIFO, packageQueueLIFO.returnQueueType());

}

TEST(Package, PackageQueueClass2){
    Package pack1 = Package();
    Package pack2 = Package();
    std::deque<Package> que;
    que.push_back(pack1);
    que.push_back(pack2);
    PackageQueue packageQueueLIFO = PackageQueue(QueueType::LIFO, que);
    PackageQueue packageQueueFIFO = PackageQueue(QueueType::FIFO, que);

    packageQueueFIFO.putPackageInQueue(pack1);
    packageQueueFIFO.putPackageInQueue(pack2);
    packageQueueLIFO.putPackageInQueue(pack1);
    packageQueueLIFO.putPackageInQueue(pack2);

    EXPECT_EQ(packageQueueFIFO.popPackage().getPackageID(), pack1.getPackageID());
    EXPECT_EQ(packageQueueFIFO.popPackage().getPackageID(), pack2.getPackageID());
    EXPECT_EQ(packageQueueLIFO.popPackage().getPackageID(), pack2.getPackageID());
    EXPECT_EQ(packageQueueLIFO.popPackage().getPackageID(), pack1.getPackageID());

}

*/