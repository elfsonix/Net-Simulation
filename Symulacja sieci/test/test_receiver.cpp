//
// Created by Kasia on 2019-01-01.
#include <PackageQueue.hpp>
#include <Storehouse.hpp>
#include "gtest/gtest.h"
#include "ReceiverPreferences.hpp"

TEST(TestReceiver, RandomNumbers){
    Package pack1 = Package();
    Package pack2 = Package();
    std::deque<Package> que;
    que.push_back(pack1);
    que.push_back(pack2);
    PackageQueue packageQueueLIFO = PackageQueue(QueueType::LIFO, que);
    std::unique_ptr<Package> ptr1 = std::make_unique<Package>(pack1);
    std::unique_ptr<Package> ptr2 = std::make_unique<Package>(pack2);
    Storehouse storehouse1 = Storehouse(ptr1, 3);
    Storehouse storehouse2 = Storehouse(ptr2, 4);
    std::vector<IPackageReceiver*> vec;
    vec.push_back(&storehouse1);
    vec.push_back(&storehouse2);
    std::function<double()> function2 = ([](){return 0.65;});
    std::function<double()> function1 = ([](){return 0.35;});
/*    std::function<std::vector<double>()> probabilities =
            std::function<std::vector<double>()>([](){return std::vector<double>{0.45, 0.55};});*/
    ReceiverPreferences receiverPreferences2 = ReceiverPreferences(vec, function2);
    ReceiverPreferences receiverPreferences1 = ReceiverPreferences(vec, function1);



   IPackageReceiver* drawnReceiver2 = receiverPreferences2.drawReceiver();

    IPackageReceiver* drawnReceiver1 = receiverPreferences1.drawReceiver();


    EXPECT_EQ(drawnReceiver2, &storehouse1);
    EXPECT_EQ(drawnReceiver1, &storehouse2);


}
