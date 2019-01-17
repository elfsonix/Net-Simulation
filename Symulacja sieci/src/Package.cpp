// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Sonia on 2019-01-09.
//

#include "Package.hpp"

ElementID Package::maxID = 1;

Package::Package() {
    _packageID = maxID;
    maxID++;
}

ElementID Package::getID() const {
    return _packageID;
}
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)