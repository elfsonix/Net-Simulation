// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Sonia on 2018-12-30.
//

#ifndef SYMULACJA_SIECI_STOREHOUSE_HPP
#define SYMULACJA_SIECI_STOREHOUSE_HPP
#include "IPackageReceiver.hpp"
#include "IPackageStockpile.hpp"
#include <memory>
#include <deque>
#include <tuple>

class Storehouse : public IPackageReceiver, public IPackageStockpile {
private:
    std::unique_ptr<Package> _packageQueue;
    ElementID _nodeId;
public:
    Storehouse(std::unique_ptr<Package>& packageStockpile, ElementID nodeId) : IPackageReceiver(), IPackageStockpile(){
        _nodeId = nodeId;
        _packageQueue = std::move(packageStockpile);

    }
    ElementID getId() {
        return _nodeId;
    }
    void receivePackage(const Package& package) override;
    std::tuple<ReceiverType, ElementID> identifyReceiver() const override;
    dequeCit cbegin() const override;
    dequeCit cend() const override;
    dequeIt begin() override;
    dequeIt end() override;
    void putPackageInQueue(Package package) override;
};


#endif //SYMULACJA_SIECI_STOREHOUSE_HPP



// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)