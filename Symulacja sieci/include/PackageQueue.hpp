//
// Created by Kasia on 2018-12-31.
//

#ifndef SYMULACJA_SIECI_PACKAGEQUEUE_HPP
#define SYMULACJA_SIECI_PACKAGEQUEUE_HPP

#include <stdexcept>
#include <queue>
#include "QueueType.hpp"
#include "IPackageQueue.hpp"

class PackageQueue : public IPackageQueue {
private:
    QueueType _queueType;
    std::deque<Package> _queue;
public:
    PackageQueue(QueueType queueType, std::deque<Package> queue);
    ~PackageQueue();
    Package popPackage() override;
    void putPackageInQueue(Package package) override;
    QueueType returnQueueType() const override;
    dequeCit cbegin() const override;
    dequeCit cend() const override;
    dequeIt begin() override;
    dequeIt end() override;
};

#endif
