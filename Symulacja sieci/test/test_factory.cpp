// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Sonia on 2019-01-11.
//

#include "gtest/gtest.h"
#include "Factory.hpp"

TEST(Factory, netCompatibilityControlTrue){
    NodeCollection<Ramp> ramps;
    NodeCollection<Worker> workers ;
    NodeCollection<Storehouse> storehouses;
    Factory myFactory = Factory(workers, ramps, storehouses);

    std::deque<Package> qS;
    PackageQueue queueS = PackageQueue(QueueType::FIFO, qS);
    Storehouse myStorehouse = Storehouse(1, std::make_unique<PackageQueue>(queueS));

    std::vector<IPackageReceiver*> receiversW2;
    std::function<double()> functionW2 = ([](){return 0.8;});
    ReceiverPreferences myPrefW2 = ReceiverPreferences(receiversW2, functionW2);
    std::deque<Package> q2;
    PackageQueue queue2 = PackageQueue(QueueType::FIFO, q2);
    Worker myWorker2 = Worker(2,1,std::make_unique<PackageQueue>(queue2), myPrefW2);
    receiversW2.push_back(&myStorehouse);

    std::vector<IPackageReceiver*> receiversW;
    std::function<double()> functionW = ([](){return 0.8;});
    ReceiverPreferences myPrefW = ReceiverPreferences(receiversW, functionW);
    std::deque<Package> q;
    PackageQueue queue = PackageQueue(QueueType::FIFO, q);
    Worker myWorker = Worker(1,1,std::make_unique<PackageQueue>(queue), myPrefW);
    receiversW.push_back(&myWorker2);
    receiversW.push_back(&myStorehouse);

    std::vector<IPackageReceiver*> receiversR;
    receiversR.push_back(&myWorker);
    std::function<double()> functionR = ([](){return 0.8;});
    ReceiverPreferences myPrefR = ReceiverPreferences(receiversR, functionR);
    Ramp myRamp = Ramp(1, 1, myPrefR);
    //EXPECT_TRUE(myRamp.getVectorOfReceivers().empty());

    myFactory.addRamp(myRamp);
    myFactory.addWorker(myWorker);
    myFactory.addWorker(myWorker2);
    myFactory.addStorehouse(myStorehouse);

    EXPECT_TRUE(myFactory.isCompatible());
}
TEST(Factory, netCompatibilityControlFalse){
    NodeCollection<Ramp> ramps;
    NodeCollection<Worker> workers ;
    NodeCollection<Storehouse> storehouses;
    Factory myFactory = Factory(workers, ramps, storehouses);

    std::vector<IPackageReceiver*> receiversR;
    std::function<double()> functionR = ([](){return 0.8;});
    ReceiverPreferences myPrefR = ReceiverPreferences(receiversR, functionR);
    Ramp myRamp = Ramp(1, 1, myPrefR);

    std::vector<IPackageReceiver*> receiversW;
    std::function<double()> functionW = ([](){return 0.8;});
    ReceiverPreferences myPrefW = ReceiverPreferences(receiversW, functionW);
    std::deque<Package> q;
    PackageQueue queue = PackageQueue(QueueType::FIFO, q);
    Worker myWorker = Worker(1,1,std::make_unique<PackageQueue>(queue), myPrefW);

    std::vector<IPackageReceiver*> receiversW2;
    std::function<double()> functionW2 = ([](){return 0.8;});
    ReceiverPreferences myPrefW2 = ReceiverPreferences(receiversW2, functionW2);
    std::deque<Package> q2;
    PackageQueue queue2 = PackageQueue(QueueType::FIFO, q2);
    Worker myWorker2 = Worker(2,1,std::make_unique<PackageQueue>(queue2), myPrefW2);

    std::deque<Package> qS;
    PackageQueue queueS = PackageQueue(QueueType::FIFO, qS);
    Storehouse myStorehouse = Storehouse(1, std::make_unique<PackageQueue>(queueS));

    receiversR.push_back(&myWorker);
    receiversW.push_back(&myWorker2);
    receiversW.push_back(&myStorehouse);

    myFactory.addRamp(myRamp);
    myFactory.addWorker(myWorker);
    myFactory.addWorker(myWorker2);
    myFactory.addStorehouse(myStorehouse);
    bool result = true;
try{
    myFactory.isCompatible();
}
catch(std::runtime_error&){
    result = false;
}

    EXPECT_FALSE(result);
}

TEST(Factory, deleteReceiver){
    NodeCollection<Ramp> ramps;
    NodeCollection<Worker> workers ;
    NodeCollection<Storehouse> storehouses;

    std::vector<IPackageReceiver*> receiversR;
    std::function<double()> function = ([](){return 0.8;});
    ReceiverPreferences myPrefR = ReceiverPreferences(receiversR, function);
    Ramp myRamp = Ramp(1, 1, myPrefR);

    std::vector<IPackageReceiver*> receiversW;
    std::function<double()> function2 = ([](){return 0.8;});
    ReceiverPreferences myPrefW = ReceiverPreferences(receiversW, function);
    std::deque<Package> queue;
    Worker myWorker = Worker(1,1, std::make_unique<PackageQueue>(QueueType::FIFO, queue), myPrefW);
    receiversR.push_back(&myWorker);

    Factory myFactory = Factory(workers, ramps, storehouses);
    myFactory.removeWorkerByID(myWorker.getID());
}
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)