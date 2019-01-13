// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Katarzyna Wątorska

#ifndef SYMULACJA_SIECI_IPACKAGERECEIVER_HPP
#define SYMULACJA_SIECI_IPACKAGERECEIVER_HPP

#include <tuple>
#include <deque>
#include "ReceiverType.hpp"
#include "Package.hpp"

using dequeCit = std::deque<Package>::const_iterator;
using dequeIt = std::deque<Package>::iterator;
using ElementID = int;

class IPackageReceiver{
public:

    //metody tylko do odczytu
    virtual dequeCit cbegin() const = 0;
    virtual dequeCit cend() const = 0;
    virtual dequeIt begin() = 0;
    virtual dequeIt end() = 0;

    virtual std::tuple<ReceiverType, ElementID> identifyReceiver() const = 0;
    virtual void receivePackage(const Package& package) = 0;

};
#endif
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
