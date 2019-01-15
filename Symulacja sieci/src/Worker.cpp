//
// Created by Sonia on 2019-01-09.

#include "Worker.hpp"

void Worker::receivePackage(const Package &package) {
    //Poprawić
}

std::tuple<ReceiverType, ElementID> Worker::identifyReceiver() const {
    return std::make_tuple(ReceiverType::WORKER, _nodeID);
}

dequeCit Worker::cbegin() const {
    return dequeCit();  //Poprawić
}

dequeCit Worker::cend() const {
    return dequeCit();  //Poprawić
}

dequeIt Worker::begin() const {
    return dequeIt();   //Poprawić
}

dequeIt Worker::end() const {
    return dequeIt();   //Poprawić
}

Package Worker::popPackage() {
    return Package();   //Poprawić
}

QueueType Worker::returnQueueType() const {
    return _queueType;
}

void Worker::processPackage() {
    //Poprawić
}

void Worker::putPackageInQueue(const Package &package) {

}
