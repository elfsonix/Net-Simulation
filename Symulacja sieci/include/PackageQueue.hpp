//
// Created by Kasia on 2018-12-31.
//

#ifndef SYMULACJA_SIECI_PACKAGEQUEUE_HPP
#define SYMULACJA_SIECI_PACKAGEQUEUE_HPP

#include <queue>
#include "QueueType.hpp"
#include "IPackageQueue.hpp"
#include <stdexcept>


class PackageQueue : public IPackageQueue{
private:
    QueueType _queueType;
    std::deque<Package> _queue;   //przekazać w konstruktorze?
public:
    PackageQueue(QueueType queueType, std::deque<Package> queue) : _queueType(queueType) {
      _queue = std::move(queue);
    }

    Package popPackage() override;

    void putPackageInQueue(const Package& package) override;

    QueueType returnQueueType() const override {return _queueType;}
 dequeCit cbegin() const override;
 dequeCit cend() const override;
 dequeIt begin() override;
   dequeIt end() override;
};


#endif //SYMULACJA_SIECI_PACKAGEQUEUE_H
