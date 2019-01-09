// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Sonia on 2018-12-30.
//

#ifndef SYMULACJA_SIECI_FACTORY_HPP
#define SYMULACJA_SIECI_FACTORY_HPP

#endif //SYMULACJA_SIECI_FACTORY_HPP

#include "NodeCollection.hpp"
#include "Worker.hpp"
#include "Ramp.hpp"
#include "Storehouse.hpp"
#include <utility>

class Factory {
private:
    NodeCollection <Worker> _workers;
    NodeCollection <Ramp> _ramps;
    NodeCollection <Storehouse> _storehouses;
public:
    Factory(NodeCollection<Worker> workers, NodeCollection <Ramp> ramps, NodeCollection <Storehouse> storehouses) {
        _workers = std::move(workers);
        _storehouses = std::move(storehouses);
        _ramps = std::move(ramps);
    }

    void addWorker(const Worker &worker);
    void addRamp(const Ramp &ramp);
    void addStorehouse(const Storehouse &storehouse);
    bool isCompatible() const;
    std::list<Worker>::const_iterator findWorkerById(ElementID nodeId) const;
    std::list<Storehouse>::const_iterator findStorehouseById(ElementID nodeId) const;
    std::list<Ramp>::const_iterator findRampById(ElementID nodeId) const;
    void removeById(ElementID nodeID);
};

// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)