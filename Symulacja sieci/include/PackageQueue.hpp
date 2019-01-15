// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Katarzyna Wątorska

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
    PackageQueue(QueueType queueType, std::deque<Package> queue) : _queueType(queueType) {
      _queue = std::move(queue);
    }
    ~PackageQueue();
    Package popPackage() override;
    void putPackageInQueue(Package package) override;
    dequeCit cbegin() const override;
    dequeCit cend() const override;
    dequeIt begin() override;
    dequeIt end() override;
    QueueType returnQueueType() const override {return _queueType;}
};

#endif
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
