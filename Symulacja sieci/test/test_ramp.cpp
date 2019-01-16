// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Sonia on 2019-01-11.
//

#include "gtest/gtest.h"
#include "Ramp.hpp"

TEST(Ramp, GeneratePackageInTime){

}

TEST(Ramp, isProductSentToBuffer){
    std::vector<IPackageReceiver*> receivers;
    std::function<double()> function = ([](){return 1;});
    ReceiverPreferences myPref = ReceiverPreferences(receivers, function);
    Ramp myRamp = Ramp(1, 3, myPref);
    myRamp.generatePackage(3);
    EXPECT_TRUE(myRamp.returnBufferState());
}
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)