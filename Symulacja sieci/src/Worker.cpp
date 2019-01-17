// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Sonia on 2019-01-09.

#include "Worker.hpp"

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

Package Worker::popPackage() {
    return _packageQueue->popPackage();
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
                passPackageToReceiver();
                _bufferOfProcessedPackage.reset();
            }
        }
        else {
            _bufferOfProcessedPackage = popPackage();
            _processRound = 1;
        }
    }
    else putPackageInBuffer(popPackage());  //Przetwarza i od razu wysyła
}

void Worker::putPackageInQueue(const Package &package) {
    _packageQueue->putPackageInQueue(package);
}
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)