// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Sonia on 2019-01-11.
//

#include "gtest/gtest.h"
#include "NodeCollection.hpp"
#include "Ramp.hpp"

TEST(NodeCollection, findById){
    std::vector<IPackageReceiver*> receivers;
    std::function<double()> function = ([](){return 1;});
    ReceiverPreferences myPref = ReceiverPreferences(receivers, function);
    Ramp ramp1 = Ramp(1, myPref);
    Ramp ramp2 = Ramp(2, myPref);
    NodeCollection<Ramp> ramps;
    ramps.add(ramp1);
    ramps.add(ramp2);
    auto it = ramps.findById(ramp2.getID());
    EXPECT_EQ(&it, ramp2.getID());
}

TEST(NodeCollection, removeById){
    std::vector<IPackageReceiver*> receivers;
    std::function<double()> function = ([](){return 1;});
    ReceiverPreferences myPref = ReceiverPreferences(receivers, function);
    Ramp ramp1 = Ramp(1, myPref);
    Ramp ramp2 = Ramp(2, myPref);
    NodeCollection<Ramp> ramps;
    ramps.add(ramp1);
    ramps.add(ramp2);
    ramps.removeById(ramp2.getID());
    EXPECT_EQ(ramps.end(), ramps.begin());
}
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)