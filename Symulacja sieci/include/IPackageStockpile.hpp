//
// Created by Kasia on 2018-12-31.
//

#ifndef NETSIM_IPACKAGESTOCKPILE_H
#define NETSIM_IPACKAGESTOCKPILE_H

#include "QueueType.hpp"
#include "Package.hpp"
#include <deque>

using deque_cit = std::deque<Package>::const_iterator;
using deque_it = std::deque<Package>::iterator;

class IPackageStockpile{

public:
    IPackageStockpile(){};        //default constructor
    virtual void putPackageInQueue(Package package) = 0;      //metoda do umieszczenia produktu na składowisku

    //metody tylko do odczytu
    virtual deque_cit cbegin() const;
    virtual deque_cit cend() const;
    virtual deque_it begin();
    virtual deque_it end();

};


#endif //NETSIM_IPACKAGESTOCKPILE_H
