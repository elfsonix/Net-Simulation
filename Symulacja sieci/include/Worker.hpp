// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Sonia on 2018-12-30.
//

#ifndef SYMULACJA_SIECI_WORKER_HPP
#define SYMULACJA_SIECI_WORKER_HPP

#include "PackageSender.hpp"
#include "IPackageReceiver.hpp"
#include "IPackageQueue.hpp"
#include <memory>
#include <deque>
#include <tuple>
#include <optional>
#include "QueueType.hpp"

class Worker : public PackageSender, public IPackageReceiver, public IPackageQueue {
private:
    std::unique_ptr <Package> _packageQueue;    //lista oczekujących paczek
    ElementID _nodeID{};
    std::optional<Package> _bufferOfProcessedPackage;   //bufor z aktualnie przetwarzaną paczką
    int _processTime;   //ile kolejek zajmuje przetworzenie produktu
    QueueType _queueType;
public:
    Worker(std::unique_ptr<Package> packageQueue,
            ElementID nodeID,
            const ReceiverPreferences &receiverPreferences,
            int processTime, QueueType queueType)
    : PackageSender(receiverPreferences) {
        _nodeID = nodeID;
        _processTime = processTime;
        _packageQueue = std::move(packageQueue);
        _bufferOfProcessedPackage = std::nullopt_t;
        _queueType = queueType;
    }

    void putPackageInQueue(const Package& package) override;
    void processPackage();
    void receivePackage(const Package& package) override;
    std::tuple<ReceiverType, ElementID> identifyReceiver() const override;
    dequeCit cbegin() const override;
    dequeCit cend() const override;
    dequeIt begin() const override;
    dequeIt end() const override;
    Package popPackage() override;
    QueueType returnQueueType() const override;

};

#endif //SYMULACJA_SIECI_WORKER_HPP
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)