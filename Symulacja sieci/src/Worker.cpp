// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Sonia on 2019-01-09.

#include <Worker.hpp>

#include "Worker.hpp"

Worker::Worker(ElementID nodeID, int processTime, std::unique_ptr<PackageQueue> packageQueue,
               const ReceiverPreferences &receiverPreferences)
        : PackageSender(receiverPreferences) {
    _nodeID = nodeID;
    _processTime = processTime;
    _packageQueue = std::move(packageQueue);
    _bufferOfProcessedPackage = std::nullopt;
    _processRound = 0;
    _queueType = _packageQueue->returnQueueType();
}

ElementID Worker::getID() const{
    return _nodeID;
}

void Worker::receivePackage(const Package &package) {
    _packageQueue->putPackageInQueue(package);
}

std::tuple<ReceiverType, ElementID> Worker::identifyReceiver() const {
    return std::make_tuple(ReceiverType::WORKER, _nodeID);
}

dequeCit Worker::cbegin() const {
    return _packageQueue->cbegin();
}

dequeCit Worker::cend() const {
    return _packageQueue->cend();
}

dequeIt Worker::begin() {
    return _packageQueue->begin();
}

dequeIt Worker::end() {
    return _packageQueue->end();
}

QueueType Worker::returnQueueType() const {
    return _queueType;
}

void Worker::processPackage() {
    if (_processTime>1){
        if(_bufferOfProcessedPackage.has_value()){
            _processRound++;    //przetworzenie
            if((_processRound = _processTime)){   //jeśli to ostatnie przetworzenie - wyślij dalej
                _processRound = 0;
                putPackageInBuffer(_bufferOfProcessedPackage.value());
                _bufferOfProcessedPackage.reset();
            }
        }
        else {
            _bufferOfProcessedPackage = _packageQueue->popPackage();
            _processRound = 1;
        }
    }
    else putPackageInBuffer(_packageQueue->popPackage());  //Przetwarza i od razu wysyła
}
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)