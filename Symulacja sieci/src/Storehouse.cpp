// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Sonia on 2019-01-09.
//
#include <Storehouse.hpp>

#include "Storehouse.hpp"

void Storehouse::receivePackage(const Package &package) {

}

std::tuple<ReceiverType, ElementID> Storehouse::identifyReceiver() const {
    return std::tuple<ReceiverType, ElementID>();
}

dequeCit Storehouse::cbegin() const {
    return dequeCit();
}

dequeCit Storehouse::cend() const {
    return dequeCit();
}

dequeIt Storehouse::begin() {
    return dequeIt();
}

dequeIt Storehouse::end() {
    return dequeIt();
}

void Storehouse::putPackageInQueue(const Package &package) {

}
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)