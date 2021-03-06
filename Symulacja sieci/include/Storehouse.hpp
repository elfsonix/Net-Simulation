    // 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Sonia on 2018-12-30.
//

#ifndef SYMULACJA_SIECI_STOREHOUSE_HPP
#define SYMULACJA_SIECI_STOREHOUSE_HPP

#include "PackageQueue.hpp"
#include "IPackageReceiver.hpp"
#include "IPackageStockpile.hpp"
#include "PackageQueue.hpp"
#include <memory>
#include <deque>
#include <tuple>

class Storehouse : public IPackageReceiver{
private:
    std::unique_ptr<IPackageStockpile> _packageQueue;
    ElementID _nodeId;
public:
    Storehouse(ElementID nodeId, std::unique_ptr<IPackageStockpile> packageStockpile);
    ElementID getID() const;
    void receivePackage(const Package& package) override;
    std::tuple<ReceiverType, ElementID> identifyReceiver() const override;
    dequeCit cbegin() const override;
    dequeCit cend() const override;
    dequeIt begin() override;
    dequeIt end() override;
};

#endif //SYMULACJA_SIECI_STOREHOUSE_HPP
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)