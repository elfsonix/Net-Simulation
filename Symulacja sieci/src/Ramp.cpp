// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Sonia on 2019-01-09.
//
#include <Ramp.hpp>

#include "Ramp.hpp"

Ramp::Ramp(ElementID nodeID, const ReceiverPreferences &receiverPreferences) : PackageSender(receiverPreferences) {
    _nodeID = nodeID;
}

void Ramp::generatePackage() {
    Package package = Package();
    putPackageInBuffer(package);
}

ElementID Ramp::getID() const {
    return _nodeID;
}


// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)