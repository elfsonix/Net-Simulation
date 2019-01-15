// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Katarzyna Wątorska



#include "PackageSender.hpp"

PackageSender::PackageSender(ReceiverPreferences receiverPreferences1) : receiverPreferences(receiverPreferences1){}

void PackageSender::passPackageToReceiver(){
    IPackageReceiver* drawnReceiver = receiverPreferences.drawReceiver();
    drawnReceiver->receivePackage(*_bufferOfPackagesReady);
    _bufferOfPackagesReady.reset();

}

void PackageSender::putPackageInBuffer(Package package){
    _bufferOfPackagesReady = std::make_optional(package);
    passPackageToReceiver();
}
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)


// inicjalizacja bufora w konstruktorze
// bufor Package czy *Package