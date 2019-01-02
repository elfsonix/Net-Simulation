//
// Created by Sonia on 2018-12-30.
//

#ifndef SYMULACJA_SIECI_STOREHOUSE_HPP
#define SYMULACJA_SIECI_STOREHOUSE_HPP

#endif //SYMULACJA_SIECI_STOREHOUSE_HPP

#include "../Storage Package/Package.hpp"
#include <memory>

class Storehouse {
private:
    std::unique_ptr<Package> _package_queue;
public:
    Storehouse(){}
    void receiveProduct();
};
