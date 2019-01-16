// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Sonia on 2019-01-09.
//
#include <Storehouse.hpp>

#include "Storehouse.hpp"

Storehouse::Storehouse(ElementID nodeId, std::unique_ptr<PackageQueue> packageStockpile) {
    _nodeId = nodeId;
    _packageQueue = std::move(packageStockpile);

}

void Storehouse::receivePackage(const Package &package) {
    putPackageInQueue(package);
}

std::tuple<ReceiverType, ElementID> Storehouse::identifyReceiver() const {
    return std::tuple<ReceiverType, ElementID>();
}

dequeCit Storehouse::cbegin() const {
    return _packageQueue->cbegin();
}

dequeCit Storehouse::cend() const {
    return _packageQueue->cend();
}

dequeIt Storehouse::begin() {
    return _packageQueue->begin();
}

dequeIt Storehouse::end() {
    return _packageQueue->end();
}

void Storehouse::putPackageInQueue(const Package &package) {
    _packageQueue->putPackageInQueue(package);
}

ElementID Storehouse::getId() const{
    return _nodeId;
}
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)