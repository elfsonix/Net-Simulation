// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Sonia on 2018-12-30.
//

#ifndef SYMULACJA_SIECI_WORKER_HPP
#define SYMULACJA_SIECI_WORKER_HPP

#endif //SYMULACJA_SIECI_WORKER_HPP
<<<<<<< HEAD
<<<<<<< HEAD


#include <memory>
#include <deque>
#include <tuple>
#include "PackageSender.hpp"
#include "IPackageReceiver.hpp"

=======

=======

>>>>>>> Kasia-develop
#include "Package.hpp"
#include <memory>
#include <deque>
#include <tuple>
<<<<<<< HEAD
>>>>>>> develop
=======
>>>>>>> Kasia-develop

class Worker : public PackageSender, public IPackageReceiver, public IPackageQueue {
private:
    std::unique_ptr <Package> _package_queue;
    ElementID _nodeId;
public:
    Worker(std::unique_ptr<Package> package_queue, ElementID nodeId) : PackageSender(), IPackageReceiver(), IPackageQueue() {}
    void processPackage();
    void receivePackage(const Package& package);
    std::tuple<ReceiverType, ElementID> identifyReceiver() const;
    std::deque<Package>::const_iterator  cbegin() const;
    std::deque<Package>::const_iterator cend() const;
    std::deque<Package>::iterator begin() const;
    std::deque<Package>::iterator end() const;
    Package popPackage();
    QueueType returnQueueType() const;

};
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)