//
// Created by Kasia on 2018-12-31.
//

#include "gtest/gtest.h"
#include "Package.hpp"

TEST(PackageTest, arePackageIdsDifferent){
    Package pack1 = Package();
    Package pack2 = Package();
    EXPECT_EQ(pack1.getID(), 1);
    EXPECT_EQ(pack2.getID(), 2);

}