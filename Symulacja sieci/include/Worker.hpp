// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Sonia on 2018-12-30.
//

#ifndef SYMULACJA_SIECI_WORKER_HPP
#define SYMULACJA_SIECI_WORKER_HPP

#endif //SYMULACJA_SIECI_WORKER_HPP

#include "Package.hpp"
#include "PackageSender.hpp"
#include "IPackageReceiver.hpp"
#include "IPackageQueue.hpp"
#include <memory>
#include <deque>
#include <tuple>

class Worker : public PackageSender, public IPackageReceiver, public IPackageQueue {
private:
    std::unique_ptr <Package> _package_queue;
    ElementID _nodeId;
public:
    Worker(std::unique_ptr<Package> package_queue, ElementID nodeId) : PackageSender(), IPackageReceiver(), IPackageQueue() {}
    void processPackage();
    void receivePackage(const Package& package) override;
    std::tuple<ReceiverType, ElementID> identifyReceiver() const override;
    deque_cit cbegin() const override;
    deque_cit cend() const override;
    deque_it begin() const override;
    deque_it end() const override;
    Package popPackage() override;
    QueueType returnQueueType() const override;

};
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)