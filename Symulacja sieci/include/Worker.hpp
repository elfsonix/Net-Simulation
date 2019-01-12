// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Sonia on 2018-12-30.
//

#ifndef SYMULACJA_SIECI_WORKER_HPP
#define SYMULACJA_SIECI_WORKER_HPP

#include "PackageSender.hpp"
#include "IPackageReceiver.hpp"
#include "IPackageQueue.hpp"
#include "PackageQueue.hpp"
#include <memory>
#include <deque>
#include <tuple>
#include <optional>
#include "QueueType.hpp"

class Worker : public PackageSender, public IPackageReceiver, public IPackageQueue {
private:
    std::unique_ptr <PackageQueue> _packageQueue;    //lista oczekujących paczek
    ElementID _nodeID{};
    int _processTime;   //ile kolejek zajmuje przetworzenie produktu
    int _processRound;  //w którym stadium jest przetwarzany produkt
    QueueType _queueType;
public:
    std::optional<Package> _bufferOfProcessedPackage;   //bufor z aktualnie przetwarzaną paczką
    Worker(ElementID nodeID, int processTime, std::unique_ptr<PackageQueue> packageQueue,
            const ReceiverPreferences &receiverPreferences)
    : PackageSender(receiverPreferences) {
        _nodeID = nodeID;
        _processTime = processTime;
        _packageQueue = std::move(packageQueue);
        _bufferOfProcessedPackage = std::nullopt;
        _processRound = 0;
        _queueType = _packageQueue->returnQueueType();
    }

    //Własne
    void processPackage();
    //Dziedziczone
    void putPackageInQueue(const Package& package) override;
    void receivePackage(const Package& package) override;
    std::tuple<ReceiverType, ElementID> identifyReceiver() const override;
    dequeCit cbegin() const override;   //references a constant value of beginning of _packageQueue
    dequeCit cend() const override;
    dequeIt begin() const override;
    dequeIt end() const override;
    Package popPackage() override;
    QueueType returnQueueType() const override;


};

#endif //SYMULACJA_SIECI_WORKER_HPP
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)