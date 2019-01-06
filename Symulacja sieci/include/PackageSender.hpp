//
// Created by Kasia on 2018-12-31.
//

#ifndef NETSIM_PACKAGESENDER_H
#define NETSIM_PACKAGESENDER_H
#include <experimental/optional>
#include "Package.hpp"
#include "ReceiverPreferences.hpp"

class PackageSender{
private:
    void passProductToReceiver();
    std::experimental::optional<Package> bufferOfProductsReady;

public:
    ReceiverPreferences receiverPreferences;
    PackageSender(ReceiverPreferences receiverPreferences1) : receiverPreferences(receiverPreferences1) {}

    void putPackageInBuffer(Package package);

};
#endif //NETSIM_PACKAGESENDER_H
