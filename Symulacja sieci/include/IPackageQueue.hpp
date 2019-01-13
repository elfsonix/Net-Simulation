// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Katarzyna Wątorska

#ifndef SYMULACJA_SIECI_IPACKAGEQUEUE_HPP
#define SYMULACJA_SIECI_IPACKAGEQUEUE_HPP

#include "QueueType.hpp"
#include "IPackageStockpile.hpp"

class IPackageQueue : public IPackageStockpile{

public:
    virtual Package popPackage() = 0;
    virtual QueueType returnQueueType() const = 0;
};

#endif
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)