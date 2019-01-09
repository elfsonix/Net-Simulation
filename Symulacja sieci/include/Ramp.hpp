// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Sonia on 2018-12-30.
//

#ifndef SYMULACJA_SIECI_RAMP_HPP
#define SYMULACJA_SIECI_RAMP_HPP

#endif //SYMULACJA_SIECI_RAMP_HPP

#include "Package.hpp"

class Ramp : public PackageSender {
private:
    ElementID _nodeId;
public:
    Ramp(ElementID nodeId) : PackageSender();
    void generatePackage() const;
};
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)