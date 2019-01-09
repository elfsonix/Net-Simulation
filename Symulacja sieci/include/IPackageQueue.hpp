//
// Created by Kasia on 2018-12-31.
//

#ifndef NETSIM_IPACKAGEQUEUE_H
#define NETSIM_IPACKAGEQUEUE_H

#include "IPackageStockpile.hpp"
#include "QueueType.hpp"


class IPackageQueue : public IPackageStockpile{

public:

    IPackageQueue() {};    //default constructor
    virtual Package popPackage()= 0;
    virtual QueueType returnQueueType() = 0;

};
#endif //NETSIM_IPACKAGEQUEUE_H
