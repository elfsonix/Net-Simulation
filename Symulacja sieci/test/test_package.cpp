// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Kasia on 2018-12-31.
//

#include "gtest/gtest.h"
#include "Package.hpp"

TEST(Package, arePackageIdsDifferent){
    Package pack1 = Package();
    Package pack2 = Package();
    EXPECT_EQ(pack1.getID(), 1);
    EXPECT_EQ(pack2.getID(), 2);

}
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)