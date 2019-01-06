//
// Created by Kasia on 2018-12-31.
//

#ifndef NETSIM_PACKAGE_H
#define NETSIM_PACKAGE_H
int static maxID = 1;

using ElementID = int;
class Package{

private:
    ElementID _ID;

public:

    Package(){_ID = maxID; maxID++;}
    ElementID getID(){return _ID;}

};
#endif //NETSIM_PACKAGE_H
