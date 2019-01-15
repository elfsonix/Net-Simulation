//
// Created by Sonia on 2019-01-09.
//
//
#include "Factory.hpp"

void Factory::addRamp(const Ramp &ramp) {

}

void Factory::addWorker(const Worker &worker) {

}

void Factory::addStorehouse(const Storehouse &storehouse) {

}

bool Factory::isCompatible() const {
    return false;
}

std::list<Worker>::const_iterator Factory::findWorkerById(ElementID nodeId) const {
    return std::__cxx11::list<Worker, std::allocator<Worker>>::const_iterator();
}

std::list<Storehouse>::const_iterator Factory::findStorehouseById(ElementID nodeId) const {
    return std::__cxx11::list<Storehouse, std::allocator<Storehouse>>::const_iterator();
}

std::list<Ramp>::const_iterator Factory::findRampById(ElementID nodeId) const {
    return std::__cxx11::list<Ramp, std::allocator<Ramp>>::const_iterator();
}

void Factory::removeById(ElementID nodeID) {

}