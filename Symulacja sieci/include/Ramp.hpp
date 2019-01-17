// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Sonia on 2018-12-30.
//

#ifndef SYMULACJA_SIECI_RAMP_HPP
#define SYMULACJA_SIECI_RAMP_HPP

#include "PackageSender.hpp"
using TimeOffSet = int;
using Time = int;

class Ramp : public PackageSender {
private:
    ElementID _nodeID;
    TimeOffSet _timeOffSet;
public:
    Ramp(ElementID nodeID,TimeOffSet timeOffSet, const ReceiverPreferences &receiverPreferences);
    void generatePackage(Time time);
    ElementID getID() const;
};

#endif //SYMULACJA_SIECI_RAMP_HPP
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)