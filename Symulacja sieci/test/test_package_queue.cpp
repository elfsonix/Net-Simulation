// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Katarzyna Wątorska


#include "gtest/gtest.h"
#include "Package.hpp"
#include "PackageQueue.hpp"


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

EXPECT_EQ(packageQueueFIFO.popPackage().getID(), pack1.getID());
EXPECT_EQ(packageQueueFIFO.popPackage().getID(), pack2.getID());
EXPECT_EQ(packageQueueLIFO.popPackage().getID(), pack2.getID());
EXPECT_EQ(packageQueueLIFO.popPackage().getID(), pack1.getID());

}
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)

