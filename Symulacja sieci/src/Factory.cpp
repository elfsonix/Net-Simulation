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

bool Factory::isCompatible() {
    std::list<std::list<Worker>::const_iterator> hasExit;    //przeszukany
    std::list<std::list<Worker>::const_iterator> checkForExit;   //oczekujący na przeszukanie
    for(const Ramp& ramp : _ramps){
        auto receivers = ramp.getVectorOfReceivers();
        if(receivers.empty()) throw std::runtime_error("Brak połączeń wychodzących z rampy. ID: "+ std::to_string(ramp.getID()));
        for(auto receiver: receivers){
            if(std::get<0>(receiver->identifyReceiver())==ReceiverType::WORKER){
                checkForExit.push_back(findWorkerByID(std::get<1>(receiver->identifyReceiver())));
            }
            while(!checkForExit.empty()){
                auto worker = checkForExit.back();
                checkForExit.pop_back();
                bool checkReceivers = true;
                for(auto it : hasExit){
                    if(findWorkerByID(std::get<1>(receiver->identifyReceiver()))== it) checkReceivers=false;
                }
                if(checkReceivers){
                    auto receiversW = worker->getVectorOfReceivers();
                    if(receiversW.empty()) throw std::runtime_error("Brak połączeń wychodzących od pracownika. ID: "+ std::to_string(worker->getID()));
                    for(auto receiverW : receiversW){
                        bool addReceivers = true;
                        for(auto it : hasExit){
                            if(findWorkerByID(std::get<1>(receiverW->identifyReceiver()))== it) addReceivers = false;
                        }
                        if(addReceivers){
                            checkForExit.push_back(findWorkerByID(std::get<1>(receiverW->identifyReceiver())));
                        }
                    }
                    hasExit.push_back(worker);
                }
            }
        }
    }
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

std::list<Worker>::iterator Factory::getWorkers() {
    return _workers.begin();
}

std::list<Ramp>::iterator Factory::getRamps() {
    return _ramps.begin();
}

std::list<Storehouse>::iterator Factory::getStorehouses() {
    return _storehouses.begin();
}
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
