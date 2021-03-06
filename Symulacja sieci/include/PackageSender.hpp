// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Katarzyna Wątorska

#ifndef SYMULACJA_SIECI_PACKAGESENDER_HPP
#define SYMULACJA_SIECI_PACKAGESENDER_HPP
#include <optional>
#include "ReceiverPreferences.hpp"

class PackageSender {


private:
    std::optional<Package> _bufferOfPackagesReady;

public:
    ReceiverPreferences receiverPreferences;
    void passPackageToReceiver();
    PackageSender(const ReceiverPreferences& receiverPreferences1);

    void putPackageInBuffer(Package package);
    std::vector<IPackageReceiver*> getVectorOfReceivers() const;
    bool returnBufferState();
};

#endif
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
