// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Katarzyna Wątorska

#include <PackageQueue.hpp>
#include <Storehouse.hpp>
#include "gtest/gtest.h"
#include "ReceiverPreferences.hpp"

TEST(TestReceiver, RandomNumbers){
    Package pack1 = Package();
    Package pack2 = Package();
    Package pack3 = Package();
    std::deque<Package> que;
    que.push_back(pack1);
    que.push_back(pack2);
    que.push_back(pack3);
    PackageQueue packageQueueLIFO = PackageQueue(QueueType::LIFO, que);
    std::unique_ptr<PackageQueue> ptr1 = std::make_unique<PackageQueue>(packageQueueLIFO);
    std::unique_ptr<PackageQueue> ptr2 = std::make_unique<PackageQueue>(packageQueueLIFO);
    Storehouse storehouse1 = Storehouse(3, std::move(ptr1));
    Storehouse storehouse2 = Storehouse(4, std::move(ptr2));
    std::unique_ptr<Package> ptr3 = std::make_unique<Package>(pack3);
    Storehouse storehouse3 = Storehouse(ptr3, 3);
    std::vector<IPackageReceiver*> vec;
    vec.push_back(&storehouse1);
    vec.push_back(&storehouse2);
    vec.push_back(&storehouse3);
    std::function<double()> function3 = ([](){return 0.90;});
    std::function<double()> function1 = ([](){return 0.15;});
    std::function<double()> function2 = ([](){return 0.54;});

    ReceiverPreferences receiverPreferences2 = ReceiverPreferences(vec, function2);
    ReceiverPreferences receiverPreferences1 = ReceiverPreferences(vec, function1);
    ReceiverPreferences receiverPreferences3 = ReceiverPreferences(vec, function3);

    IPackageReceiver* drawnReceiver2 = receiverPreferences2.drawReceiver();

    IPackageReceiver* drawnReceiver1 = receiverPreferences1.drawReceiver();
    IPackageReceiver* drawnReceiver3 = receiverPreferences3.drawReceiver();


    EXPECT_EQ(drawnReceiver2, &storehouse2);
    EXPECT_EQ(drawnReceiver1, &storehouse1);
    EXPECT_EQ(drawnReceiver3, &storehouse3);


}

TEST(ReceiverTest, addReceiver){
    Package pack1 = Package();
    Package pack2 = Package();

    std::deque<Package> que;
    que.push_back(pack1);
    que.push_back(pack2);

    PackageQueue packageQueueLIFO = PackageQueue(QueueType::LIFO, que);
    std::unique_ptr<Package> ptr1 = std::make_unique<Package>(pack1);
    std::unique_ptr<Package> ptr2 = std::make_unique<Package>(pack2);

    Storehouse storehouse1 = Storehouse(ptr1, 1);
    Storehouse storehouse2 = Storehouse(ptr2, 2);

    std::vector<IPackageReceiver*> vec;
    vec.push_back(&storehouse1);
    vec.push_back(&storehouse2);

    std::function<double()> function3 = ([](){return 0.90;});
    std::function<double()> function1 = ([](){return 0.40;});
    std::function<double()> function2 = ([](){return 0.54;});

    ReceiverPreferences receiverPreferences2 = ReceiverPreferences(vec, function2);
    ReceiverPreferences receiverPreferences1 = ReceiverPreferences(vec, function1);

    IPackageReceiver* drawnReceiver1 = receiverPreferences1.drawReceiver();

    EXPECT_EQ(drawnReceiver1, &storehouse1);

    Package pack3 = Package();
    que.push_back(pack3);
    std::unique_ptr<Package> ptr3 = std::make_unique<Package>(pack3);
    Storehouse storehouse3 = Storehouse(ptr3, 3);
    receiverPreferences1.addReceiver(&storehouse3);
    IPackageReceiver* drawnReceiver2 = receiverPreferences1.drawReceiver();

    EXPECT_EQ(drawnReceiver2, &storehouse2);

}

TEST(ReceiverTest, deleteReceiver){
    Package pack1 = Package();
    Package pack2 = Package();
    Package pack3 = Package();
    std::deque<Package> que;
    que.push_back(pack1);
    que.push_back(pack2);
    que.push_back(pack3);
    PackageQueue packageQueueLIFO = PackageQueue(QueueType::LIFO, que);
    std::unique_ptr<Package> ptr1 = std::make_unique<Package>(pack1);
    std::unique_ptr<Package> ptr2 = std::make_unique<Package>(pack2);
    std::unique_ptr<Package> ptr3 = std::make_unique<Package>(pack3);
    Storehouse storehouse1 = Storehouse(ptr1, 1);
    Storehouse storehouse2 = Storehouse(ptr2, 2);
    Storehouse storehouse3 = Storehouse(ptr3, 3);
    std::vector<IPackageReceiver*> vec;
    vec.push_back(&storehouse1);
    vec.push_back(&storehouse2);
    vec.push_back(&storehouse3);
    std::function<double()> function1 = ([](){return 0.45;});
    ReceiverPreferences receiverPreferences1 = ReceiverPreferences(vec, function1);
    IPackageReceiver* drawnReceiver1 = receiverPreferences1.drawReceiver();
    EXPECT_EQ(drawnReceiver1, &storehouse2);
    receiverPreferences1.deleteReceiver(&storehouse2);
    IPackageReceiver* drawnReceiver2 = receiverPreferences1.drawReceiver();
    EXPECT_EQ(drawnReceiver2, &storehouse1);

}
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)