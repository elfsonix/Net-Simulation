// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Sonia on 2019-01-09.
//
#include "Factory.hpp"

void Factory::addRamp(const Ramp &ramp) {
    _ramps.add(ramp);
}
/*
void Factory::addWorker(const Worker &worker) {
    _workers.add(worker);
}

void Factory::addStorehouse(const Storehouse &storehouse) {
    _storehouses.add(storehouse);
}

bool Factory::isCompatible() const {
    return true;
}

std::list<Worker>::const_iterator Factory::findWorkerByID(ElementID nodeID) const {
    return _workers.cfindById(nodeID);  //undefined ref?

}

std::list<Storehouse>::const_iterator Factory::findStorehouseByID(ElementID nodeID) const {
    return _storehouses.cfindById(nodeID);
}

std::list<Ramp>::const_iterator Factory::findRampByID(ElementID nodeID) const {
    return _ramps.cfindById(nodeID);
}*/

void Factory::removeStorehouseByID(ElementID nodeID) {
    _storehouses.removeById(nodeID);
}

void Factory::removeWorkerByID(ElementID nodeID) {
    _workers.removeById(nodeID);
}

void Factory::removeRampByID(ElementID nodeID) {
    _ramps.removeById(nodeID);
}
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)