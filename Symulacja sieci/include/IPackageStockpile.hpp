//
// Created by Kasia on 2018-12-31.
//

#ifndef SYMULACJA_SIECI_IPACKAGESTOCKPILE_HPP
#define SYMULACJA_SIECI_IPACKAGESTOCKPILE_HPP


#include "Package.hpp"
#include <deque>

using dequeCit = std::deque<Package>::const_iterator;
using dequeIt = std::deque<Package>::iterator;

class IPackageStockpile{

public:
    //IPackageStockpile(){};        //default constructor
    virtual void putPackageInQueue(const Package& package) = 0;      //metoda do umieszczenia produktu na składowisku

    //metody tylko do odczytu
    virtual dequeCit cbegin() const = 0;
    virtual dequeCit cend() const = 0;
    virtual dequeIt begin() = 0;
    virtual dequeIt end() = 0;

};


#endif //SYMULACJA_SIECI_IPACKAGESTOCKPILE_H
