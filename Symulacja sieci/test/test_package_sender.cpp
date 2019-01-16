
//
// Created by Kasia on 2019-01-15.
//


#include "Storehouse.hpp"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "PackageQueue.hpp"
#include "PackageSender.hpp"
/*using ::testing::Return;
class MockReceiver : public IPackageReceiver{
    MOCK_METHOD1(receivePackage, void(const Package&));
};*/


TEST(PackageSender, isBufferClear){
    Package pack1 = Package();
    Package pack2 = Package();
    Package pack3 = Package();
    Package pack4 = Package();

    std::deque<Package> que;
    que.push_back(pack1);
    que.push_back(pack2);
    que.push_back(pack3);
    que.push_back(pack4);
    std::deque<Package> que2;
    que2.push_back(pack1);
    que2.push_back(pack2);
    que2.push_back(pack3);
    que2.push_back(pack4);
    PackageQueue packageQueueLIFO = PackageQueue(QueueType::LIFO, que);
    PackageQueue packageQueueFIFO = PackageQueue(QueueType::FIFO, que2);
    std::unique_ptr<PackageQueue> ptr1 = std::make_unique<PackageQueue>(packageQueueLIFO);
    std::unique_ptr<PackageQueue> ptr2 = std::make_unique<PackageQueue>(packageQueueFIFO);
    Storehouse storehouse1 = Storehouse(3, std::move(ptr1));
    Storehouse storehouse2 = Storehouse(4, std::move(ptr2));
    //MockReceiver mockReceiver;

    // EXPECT_CALL(mockReceiver, receivePackage(pack4).Times(1));


    std::vector<IPackageReceiver*> vec;
    vec.push_back(&storehouse1);
    vec.push_back(&storehouse2);

    std::function<double()> function2 = ([](){return 0.54;});

    ReceiverPreferences receiverPreferences2 = ReceiverPreferences(vec, function2);

    PackageSender packageSender = PackageSender(receiverPreferences2);
    packageSender.putPackageInBuffer(pack4);

    EXPECT_EQ(packageSender.returnBufferState(), 0);
    //EXPECT_EQ(storehouse2.returnQueueState(), pack4);
}