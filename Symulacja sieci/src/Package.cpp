//
// Created by Sonia on 2019-01-09.
//

#include "Package.hpp"

ElementID Package::maxID = 1;

Package::Package() {
    _packageID = maxID;
    maxID++;
}

Package::~Package(){
}

ElementID Package::getPackageID() const {
    return _packageID;
}