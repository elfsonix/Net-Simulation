//
// Created by Kasia on 2019-01-01.
//

#ifndef NETSIM_WORKER_H
#define NETSIM_WORKER_H

#include "IPackageReceiver.hpp"
#include <memory>
class Worker : public IPackageReceiver
{
private:
    std::unique_ptr <Package> _package_queue;
public:
    Worker() : IPackageReceiver(){}
    void processPackage(){}
    void receiveProduct() override {}
};
#endif //NETSIM_WORKER_H
