//
// Created by Kasia on 2018-12-28.
//

#ifndef SYMULACJA_SIECI_IPACKAGERECEIVER_HPP
#define SYMULACJA_SIECI_IPACKAGERECEIVER_HPP

#include <tuple>
#include <deque>
#include "ReceiverType.hpp"

using dequeCit = std::deque<Package>::const_iterator;
using dequeIt = std::deque<Package>::iterator;
using ElementID = int;

class IPackageReceiver{
public:

    //metody tylko do odczytu
    virtual dequeCit cbegin() const = 0;
    virtual dequeCit cend() const = 0;
    virtual dequeIt begin() const = 0;
    virtual dequeIt end() const = 0;

    virtual std::tuple<ReceiverType, ElementID> identifyReceiver() const = 0;
    virtual void receivePackage(const Package& package) = 0;


};


#endif //NETSIM_IPACKAGERECEIVER_H
