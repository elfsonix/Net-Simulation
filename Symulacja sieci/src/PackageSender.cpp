//
// Created by Kasia on 2019-01-06.
//


#include "PackageSender.hpp"
#include <optional>

void PackageSender::passPackageToReceiver(){}

void PackageSender::putPackageInBuffer(Package package){
    bufferOfPackagesReady = std::make_optional(package);
    passPackageToReceiver();
} 