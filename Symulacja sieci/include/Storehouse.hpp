// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Sonia on 2018-12-30.
//

#ifndef SYMULACJA_SIECI_STOREHOUSE_HPP
#define SYMULACJA_SIECI_STOREHOUSE_HPP

#endif //SYMULACJA_SIECI_STOREHOUSE_HPP

#include "Package.hpp"
#include "IPackageReceiver.hpp"
#include "IPackageStockpile.hpp"
#include <memory>
#include <deque>
#include <tuple>

class Storehouse : public IPackageReceiver, public IPackageStockpile {
private:
    std::unique_ptr<Package> _package_queue;
    ElementID _nodeId;
public:
    Storehouse(std::unique_ptr package_stockpile, ElementID nodeId) : IPackageReceiver(), IPackageStockpile(){}
    void receivePackage(const Package& package) override;
    std::tuple<ReceiverType, ElementID> identifyReceiver() const override;
    deque_cit  cbegin() const override;
    deque_cit cend() const override;
    deque_it begin() const override;
    deque_it end() const override;
};
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)