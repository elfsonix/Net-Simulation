//
// Created by Kasia on 2019-01-23.
//

#ifndef SYMULACJA_SIECI_DRAWNUMBER_H
#define SYMULACJA_SIECI_DRAWNUMBER_H

#include <functional>
#include <cstdlib>
#include <stdexcept>
#include <random>
#include <iostream>

#include <utility>
double drawNumber() {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen);
}
#endif //SYMULACJA_SIECI_DRAWNUMBER_H
