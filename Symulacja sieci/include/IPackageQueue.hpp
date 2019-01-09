//
// Created by Kasia on 2018-12-31.
//

#ifndef SYMULACJA_SIECI_IPACKAGEQUEUE_HPP
#define SYMULACJA_SIECI_IPACKAGEQUEUE_HPP

#include "IPackageStockpile.hpp"

class IPackageQueue : public IPackageStockpile{

public:

    IPackageQueue() {};    //default constructor
    virtual Package popPackage()= 0;
    virtual QueueType returnQueueType() const = 0;

};
#endif //NETSIM_IPACKAGEQUEUE_H
