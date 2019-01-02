//
// Created by Sonia on 2018-12-30.
//

#ifndef SYMULACJA_SIECI_PACKAGE_HPP
#define SYMULACJA_SIECI_PACKAGE_HPP

#endif //SYMULACJA_SIECI_PACKAGE_HPP

using ElementID = int;

class Package {
private:
    static ElementID maxID;
    ElementID _product_id;
public:
    Package() {
        _product_id = maxID;
        maxID++;
    }
    ElementID getProductId() {
        return _product_id;
    }
};