//
// Created by Sonia on 2018-12-30.
//

#ifndef SYMULACJA_SIECI_FACTORY_HPP
#define SYMULACJA_SIECI_FACTORY_HPP

#endif //SYMULACJA_SIECI_FACTORY_HPP

#include "NodeCollection.hpp"
#include "Worker.hpp"
#include "Ramp.hpp"
#include "Storehouse.hpp"


class Factory {
private:
    NodeCollection <Worker> _workers;
    NodeCollection <Ramp> _ramps;
    NodeCollection <Storehouse> _storehouses;
public:
    Factory(NodeCollection<Worker> workers, NodeCollection <Ramp> ramps, NodeCollection <Storehouse> storehouses) {
        _workers = workers;
        _storehouses = storehouses;
        _ramps = ramps;
    }

    void add(nodeID : ElementID);
    iterator findById(nodeId: ElementID);
    const_iterator findById(nodeId: ElementID);
    void removeById(nodeID : ElementID);
    bool isCompatible();
};