// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Sonia on 2018-12-30.
//

#ifndef SYMULACJA_SIECI_FACTORY_HPP
#define SYMULACJA_SIECI_FACTORY_HPP

#include "NodeCollection.hpp"
#include "Worker.hpp"
#include "Ramp.hpp"
#include "Storehouse.hpp"
#include <list>
#include <utility>

class Factory {
private:
    NodeCollection <Worker> _workers;
    NodeCollection <Ramp> _ramps;
    NodeCollection <Storehouse> _storehouses;
public:
    Factory(NodeCollection<Worker>& workers, NodeCollection <Ramp>& ramps, NodeCollection <Storehouse>& storehouses) {
        _workers = std::move(workers);
        _storehouses = std::move(storehouses);
        _ramps = std::move(ramps);
    }
    std::list<Worker>::iterator getWorkers();
    std::list<Ramp>::iterator getRamps();
    std::list<Storehouse>::iterator getStorehouses();

    void addWorker(Worker& worker);
    void addRamp(Ramp& ramp);
    void addStorehouse(Storehouse& storehouse);
    bool isCompatible() const;
    std::list<Worker>::const_iterator findWorkerByID(ElementID nodeID);
    std::list<Storehouse>::const_iterator findStorehouseByID(ElementID nodeID);
    std::list<Ramp>::const_iterator findRampByID(ElementID nodeID);
    void removeStorehouseByID(ElementID nodeID);
    void removeWorkerByID(ElementID nodeID);
    void removeRampByID(ElementID nodeID);
};

#endif //SYMULACJA_SIECI_FACTORY_HPP
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)