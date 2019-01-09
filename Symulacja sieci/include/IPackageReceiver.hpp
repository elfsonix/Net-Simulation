//
// Created by Kasia on 2018-12-28.
//

#ifndef NETSIM_IPACKAGERECEIVER_H
#define NETSIM_IPACKAGERECEIVER_H

#include <tuple>
#include <deque>
#include "ReceiverType.hpp"

using deque_cit = std::deque<Package>::const_iterator;
using deque_it = std::deque<Package>::iterator;
using ElementID = int;

class IPackageReceiver{
public:
    IPackageReceiver(){};

    //metody tylko do odczytu
    virtual deque_cit cbegin() const = 0;
    virtual deque_cit cend() const = 0;
    virtual deque_it begin() = 0;
    virtual deque_it end() = 0;

    virtual std::tuple<ReceiverType, ElementID> identifyReceiver() = 0;
    virtual Package receivePackage() = 0;


};


#endif //NETSIM_IPACKAGERECEIVER_H
