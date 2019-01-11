//
// Created by Kasia on 2018-12-31.
//

#ifndef SYMULACJA_SIECI_PACKAGESENDER_HPP
#define SYMULACJA_SIECI_PACKAGESENDER_HPP
#include <optional>
#include "ReceiverPreferences.hpp"

class PackageSender{
private:
    void passPackageToReceiver();
    std::optional<Package> bufferOfPackagesReady;

public:
    ReceiverPreferences receiverPreferences;
    PackageSender(ReceiverPreferences receiverPreferences1) : receiverPreferences(receiverPreferences1) {}

    void putPackageInBuffer(Package package);

};
#endif //SYMULACJA_SIECI_PACKAGESENDER_H
