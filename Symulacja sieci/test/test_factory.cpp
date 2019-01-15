// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Sonia on 2019-01-11.
//

#include "gtest/gtest.h"
#include "Factory.hpp"

TEST(Factory, netCompatibilityControl){

}

TEST(Factory, deleteReceiver){
    NodeCollection<Ramp> ramps;
    NodeCollection<Worker> workers ;
    NodeCollection<Storehouse> storehouses;
    /*
    std::vector<IPackageReceiver*> receiversR;
    std::function<double()> function = ([](){return 1;});
    ReceiverPreferences myPrefR = ReceiverPreferences(receiversR, function);
    Ramp myRamp = Ramp(1, myPrefR);

    std::vector<IPackageReceiver*> receiversW;
    std::function<double()> function2 = ([](){return 1;});
    ReceiverPreferences myPrefW = ReceiverPreferences(receiversW, function);
    std::deque<Package> queue;
    Worker myWorker = Worker(1,1, std::make_unique<PackageQueue>(QueueType::FIFO, queue), myPrefW);
    */
    Factory myFactory = Factory(workers, ramps, storehouses);
}
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)