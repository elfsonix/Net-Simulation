// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Sonia on 2019-01-09.
//
#include "Factory.hpp"

void Factory::addRamp(Ramp& ramp) {
    _ramps.add(ramp);
}

void Factory::addWorker(Worker& worker) {
    _workers.add(worker);
}

void Factory::addStorehouse(Storehouse& storehouse) {
    _storehouses.add(storehouse);
}

bool Factory::isCompatible() const {
    /*int searchForExitWorker(const Worker& worker){

    }

    auto searchForExit = [](const Ramp ramp){
        auto begin = ramp.receiverPreferences.cbegin();
        auto end = ramp.receiverPreferences.cend();
        while(begin!=end){
            if(std::get<0>(begin->first->identifyReceiver())==ReceiverType::STOREHOUSE) return 0;
            else{

            }
            begin++;
        }
        return 0;
    };

    bool uncompatibleRamps = std::for_each(_ramps.begin(), _ramps.end(), searchForExit);
    if(uncompatibleRamps>0) return false;
    else */return true;
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

NodeCollection <Worker> Factory::getWorkers() {
    return _workers;
}

NodeCollection <Ramp> Factory::getRamps() {
    return _ramps;
}

std::list<Storehouse>::iterator Factory::getStorehouses() {
    return _storehouses.begin();
}


std::list<Worker>::iterator Factory::getWorkerB() {
    return _workers.begin();
}
std::list<Worker>::iterator Factory::getWorkerE() {
    return _workers.end();
}
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
