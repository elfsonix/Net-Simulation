// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Sonia on 2018-12-30.
//

#ifndef SYMULACJA_SIECI_RAMP_HPP
#define SYMULACJA_SIECI_RAMP_HPP

#include "PackageSender.hpp"

class Ramp : public PackageSender {
private:
    ElementID _nodeID;
public:
    Ramp(ElementID nodeID, const ReceiverPreferences &receiverPreferences) : PackageSender(receiverPreferences) {
        _nodeID = nodeID;
    }
    void generatePackage() const;
};

#endif //SYMULACJA_SIECI_RAMP_HPP
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)