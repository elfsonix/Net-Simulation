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
    /*auto searchForExit = [](const Ramp ramp){
        auto begin = ramp.receiverPreferences.cbegin();
        auto end = ramp.receiverPreferences.cend();
        while(begin!=end){
            if(begin->first->identifyReceiver()==ReceiverType::STOREHOUSE) return true;
            else{

            }
        }
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

std::unique_ptr<NodeCollection<Worker>> Factory::getWorkers() {
    return std::make_unique<NodeCollection<Worker>>(_workers);
}

std::unique_ptr<NodeCollection<Ramp>> Factory::getRamps() {
    return std::make_unique<NodeCollection<Ramp>>(_ramps);
}

std::unique_ptr<NodeCollection<Storehouse>> Factory::getStorehouses() {
    return std::make_unique<NodeCollection<Storehouse>>(_storehouses);
}
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
