// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Katarzyna Wątorska



#include "PackageSender.hpp"

void PackageSender::passPackageToReceiver(){}

void PackageSender::putPackageInBuffer(Package package){
    bufferOfPackagesReady = std::make_optional(package);
    passPackageToReceiver();
}
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)