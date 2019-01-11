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
    _queue.push_back(package);
}

/*QueueType PackageQueue::returnQueueType() const {
    return _queueType;
}*/
dequeCit PackageQueue::cbegin() const {return _queue.cbegin();}
dequeCit PackageQueue::cend() const {return _queue.cend();}
dequeIt PackageQueue::begin() {return _queue.begin();}
dequeIt PackageQueue::end() {return _queue.end();}

