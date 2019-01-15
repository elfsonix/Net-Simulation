
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
    PackageQueue packageQueueLIFO = PackageQueue(QueueType::LIFO, que);
    std::unique_ptr<Package> ptr1 = std::make_unique<Package>(pack1);
    std::unique_ptr<Package> ptr2 = std::make_unique<Package>(pack2);
    std::unique_ptr<Package> ptr3 = std::make_unique<Package>(pack3);
    //MockReceiver mockReceiver;

   // EXPECT_CALL(mockReceiver, receivePackage(pack4).Times(1));
    Storehouse storehouse1 = Storehouse(ptr1, 1);
    Storehouse storehouse2 = Storehouse(ptr2, 2);
    Storehouse storehouse3 = Storehouse(ptr3, 3);

    std::vector<IPackageReceiver*> vec;
    vec.push_back(&storehouse1);
    vec.push_back(&storehouse2);
    vec.push_back(&storehouse3);

    std::function<double()> function2 = ([](){return 0.54;});

    ReceiverPreferences receiverPreferences2 = ReceiverPreferences(vec, function2);

    PackageSender packageSender = PackageSender(receiverPreferences2);
    packageSender.putPackageInBuffer(pack4);

    EXPECT_EQ(packageSender.returnBufferState(), std::nullopt);
    EXPECT_EQ(storehouse2.returnQueueState(), pack4);
}

