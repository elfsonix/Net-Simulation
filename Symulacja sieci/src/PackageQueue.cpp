//
// Created by Kasia on 2019-01-05.
//

#include "PackageQueue.hpp"

Package PackageQueue::popPackage() {
    switch(_queueType){
        case(QueueType::FIFO):
            {Package toReturn = _queue.front();
            _queue.pop_front();
            return toReturn;}
        case(QueueType::LIFO):
            {Package toReturn = _queue.back();
            _queue.pop_back();
            return toReturn;}
        default:
            throw std::invalid_argument("There is no such a type of queue available!");
        }
}

void PackageQueue::putPackageInQueue(Package package) {
    _queue.push_back(std::move(package));
}

QueueType PackageQueue::returnQueueType() {
    return _queueType;
}
