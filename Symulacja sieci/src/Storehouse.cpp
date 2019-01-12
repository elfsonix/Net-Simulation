//
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

dequeIt Storehouse::begin() const {
    return dequeIt();
}

dequeIt Storehouse::end() const {
    return dequeIt();
}

void Storehouse::putPackageInQueue(const Package &package) {

}
