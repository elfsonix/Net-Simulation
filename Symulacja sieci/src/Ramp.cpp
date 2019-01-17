// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Sonia on 2019-01-09.
//
#include <Ramp.hpp>

#include "Ramp.hpp"

Ramp::Ramp(ElementID nodeID, TimeOffSet timeOffSet, const ReceiverPreferences &receiverPreferences) : PackageSender(receiverPreferences) {
    _nodeID = nodeID;
    _timeOffSet = timeOffSet;
}

void Ramp::generatePackage(Time time) {
    if(time%_timeOffSet==0){
        Package package = Package();
        putPackageInBuffer(package);
    }
}

ElementID Ramp::getID() const {
    return _nodeID;
}


// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)