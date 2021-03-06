// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Katarzyna Wątorska


#include "PackageQueue.hpp"

PackageQueue::PackageQueue(QueueType queueType, std::deque<Package> queue) : IPackageQueue(){
    _queueType = queueType;
    _queue = std::move(queue);
}

PackageQueue::~PackageQueue(){
}

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

void PackageQueue::putPackageInQueue(const Package& package) {
    _queue.push_back(std::move(package));
}

QueueType PackageQueue::returnQueueType() const {
    return _queueType;
}
dequeCit PackageQueue::cbegin() const {return _queue.cbegin();}
dequeCit PackageQueue::cend() const {return _queue.cend();}
dequeIt PackageQueue::begin() {return _queue.begin();}
dequeIt PackageQueue::end() {return _queue.end();}

// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)

