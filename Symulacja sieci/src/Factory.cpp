// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Sonia on 2019-01-09.
//
#include "Factory.hpp"

void Factory::addRamp(Ramp ramp) {
    _ramps.add(ramp);
}

void Factory::addWorker(Worker worker) {
    _workers.add(worker);
}

void Factory::addStorehouse(Storehouse storehouse) {
    _storehouses.add(storehouse);
}

bool Factory::isCompatible() const {
    /*auto searchForExit = [](const Ramp ramp){
        int array[1];
        std::for_each(ramp.receiverPreferences.cbegin(), ramp.receiverPreferences.cend(), [](){if()})


        return true;
    };

    bool compatibility = std::for_each(_ramps.begin(), _ramps.end(), searchForExit);
    return compatibility;*/
    return true;
}

std::list<Worker>::const_iterator Factory::findWorkerByID(ElementID nodeID) {
    return _workers.cfindById(nodeID);

}

std::list<Storehouse>::const_iterator Factory::findStorehouseByID(ElementID nodeID){
    return _storehouses.cfindById(nodeID);
}

std::list<Ramp>::const_iterator Factory::findRampByID(ElementID nodeID){
    return _ramps.cfindById(nodeID);
}

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