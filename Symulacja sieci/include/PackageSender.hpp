// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Katarzyna Wątorska

#ifndef SYMULACJA_SIECI_PACKAGESENDER_HPP
#define SYMULACJA_SIECI_PACKAGESENDER_HPP
#include <optional>
#include "ReceiverPreferences.hpp"

class PackageSender{
protected:
    void passPackageToReceiver();
private:
    std::optional<Package> _bufferOfPackagesReady;

public:
    ReceiverPreferences receiverPreferences;
    PackageSender(ReceiverPreferences receiverPreferences1);

    void putPackageInBuffer(Package package);
    std::optional<Package> returnBufferState(){return _bufferOfPackagesReady.value();}

};
#endif
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
