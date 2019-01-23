
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Katarzyna Wątorska
#include <PackageQueue.hpp>
#include <Storehouse.hpp>
#include "gtest/gtest.h"
#include "ReceiverPreferences.hpp"

TEST(TestReceiver, RandomNumbers) {
    Package pack1 = Package();
    Package pack2 = Package();
    std::deque<Package> que;
    que.push_back(pack1);
    que.push_back(pack2);
    std::deque<Package> que2;
    que2.push_back(pack1);
    que2.push_back(pack2);
    PackageQueue packageQueueLIFO = PackageQueue(QueueType::LIFO, que);
    PackageQueue packageQueueFIFO = PackageQueue(QueueType::FIFO, que2);
    std::unique_ptr<PackageQueue> ptr1 = std::make_unique<PackageQueue>(packageQueueLIFO);
    std::unique_ptr<PackageQueue> ptr2 = std::make_unique<PackageQueue>(packageQueueFIFO);
   //std::unique_ptr<PackageQueue> ptr3 = std::make_unique<PackageQueue>(packageQueueFIFO);
    Storehouse storehouse1 = Storehouse(3, std::move(ptr1));
    Storehouse storehouse2 = Storehouse(4, std::move(ptr2));
    //Storehouse storehouse3 = Storehouse(5, std::move(ptr3));
    std::vector<IPackageReceiver *> vec;
    vec.push_back(&storehouse1);
    vec.push_back(&storehouse2);
    //vec.push_back(&storehouse3);

    std::function<double()> function1 = ([]() { return 0.35; });
    std::function<double()> function2 = ([]() { return 0.65; });

    ReceiverPreferences receiverPreferences1 = ReceiverPreferences(vec, function1);
    ReceiverPreferences receiverPreferences2 = ReceiverPreferences(vec, function2);


    IPackageReceiver *drawnReceiver1 = receiverPreferences1.drawReceiver();
    IPackageReceiver *drawnReceiver2 = receiverPreferences2.drawReceiver();

    EXPECT_EQ(drawnReceiver1, &storehouse1);
    EXPECT_EQ(drawnReceiver2, &storehouse2);

}





    TEST(ReceiverTest, addReceiver){
        Package pack1 = Package();
        Package pack2 = Package();

    std::deque<Package> que;
    que.push_back(pack1);
    que.push_back(pack2);
    std::deque<Package> que2;
    que2.push_back(pack1);
    que2.push_back(pack2);
    PackageQueue packageQueueLIFO = PackageQueue(QueueType::LIFO, que);
    PackageQueue packageQueueFIFO = PackageQueue(QueueType::FIFO, que2);
    std::unique_ptr<PackageQueue> ptr1 = std::make_unique<PackageQueue>(packageQueueLIFO);
    std::unique_ptr<PackageQueue> ptr2 = std::make_unique<PackageQueue>(packageQueueFIFO);
    Storehouse storehouse1 = Storehouse(3, std::move(ptr1));
    Storehouse storehouse2 = Storehouse(4, std::move(ptr2));

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
        std::unique_ptr<PackageQueue> ptr3 = std::make_unique<PackageQueue>(packageQueueLIFO);
        Storehouse storehouse3 = Storehouse (5, std::move(ptr3));
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
    std::deque<Package> que2;
    que2.push_back(pack1);
    que2.push_back(pack2);
    PackageQueue packageQueueLIFO = PackageQueue(QueueType::LIFO, que);
    PackageQueue packageQueueFIFO = PackageQueue(QueueType::FIFO, que2);
    std::unique_ptr<PackageQueue> ptr1 = std::make_unique<PackageQueue>(packageQueueLIFO);
    std::unique_ptr<PackageQueue> ptr2 = std::make_unique<PackageQueue>(packageQueueFIFO);
    Storehouse storehouse1 = Storehouse(3, std::move(ptr1));
    Storehouse storehouse2 = Storehouse(4, std::move(ptr2));
    std::unique_ptr<PackageQueue> ptr3 = std::make_unique<PackageQueue>(packageQueueLIFO);
    Storehouse storehouse3 = Storehouse (5, std::move(ptr3));
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

// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)*/
