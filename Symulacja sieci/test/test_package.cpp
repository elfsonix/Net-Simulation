//
// Created by Kasia on 2018-12-31.
//

#include "gtest/gtest.h"
#include "PackageQueue.hpp"
//#include "src/PackageQueue.cpp"

TEST(PackageTest, PackageClass){
    Package pack1 = Package();
    Package pack2 = Package();
    EXPECT_EQ(pack1.getID(), 1);
    EXPECT_EQ(pack2.getID(), 2);

}

TEST(PackageTest, PackageQueueClass1){
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

TEST(PackageTest, PackageQueueClass2){
    Package pack1 = Package();
    Package pack2 = Package();
    std::deque<Package> que;
    que.push_back(pack1);
    que.push_back(pack2);
    PackageQueue packageQueueLIFO = PackageQueue(QueueType::LIFO, que);
    PackageQueue packageQueueFIFO = PackageQueue(QueueType::FIFO, que);

    packageQueueFIFO.putProductInQueue(pack1);
    packageQueueFIFO.putProductInQueue(pack2);
    packageQueueLIFO.putProductInQueue(pack1);
    packageQueueLIFO.putProductInQueue(pack2);

    EXPECT_EQ(packageQueueFIFO.popProduct().getID(), pack1.getID());
    EXPECT_EQ(packageQueueFIFO.popProduct().getID(), pack2.getID());
    EXPECT_EQ(packageQueueLIFO.popProduct().getID(), pack2.getID());
    EXPECT_EQ(packageQueueLIFO.popProduct().getID(), pack1.getID());

}