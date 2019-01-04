//
// Created by Sonia on 2018-12-30.
//

#ifndef SYMULACJA_SIECI_WORKER_HPP
#define SYMULACJA_SIECI_WORKER_HPP

#endif //SYMULACJA_SIECI_WORKER_HPP

#include "Package.hpp"
#include <memory>

class Worker : public PackageSender {
private:
    std::unique_ptr <Package> _package_queue;
public:
    Worker() : PackageSender() {}
    void processPackage();
    void receiveProduct();
};