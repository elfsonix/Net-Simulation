//
// Created by Kasia on 2018-12-31.
//

#ifndef NETSIM_RECEIVERPREFERENCES_H
#define NETSIM_RECEIVERPREFERENCES_H

#include <map>
#include <functional>
#include <cstdlib>
#include <stdexcept>
#include <random>
#include <iostream>
#include "IPackageQueue.hpp"
#include "IPackageReceiver.hpp"


using preferences_t = std::map<IPackageReceiver*, double>;
using vector_p = std::vector<std::pair<IPackageReceiver*, double>>;
using const_iterator = preferences_t::const_iterator;
using iterator = preferences_t::iterator;


class ReceiverPreferences {
private:
    preferences_t _probabilityTable;
    std::function<std::vector<double>()> _drawnNumberVector;
    float SUM_OF_PROBABILITIES = 1.0;

    //funkcje pomocnicze dla konstruktora - zwraca wektor par (wskaźnik na odbiorcę, prawdopodobieństwa)
    vector_p convertToVector(std::vector<IPackageReceiver*> packageVector, std::vector<double> doubleVector);
    preferences_t convertToMap(vector_p pairVector);

public:
    ReceiverPreferences(std::vector<IPackageReceiver*> packageVector,
                        std::function<std::vector<double>()> drawnNumberVector){
        _drawnNumberVector = drawnNumberVector;

        std::vector<double> doubleVector = _drawnNumberVector();
        vector_p v = convertToVector(packageVector, doubleVector);
        _probabilityTable = convertToMap(v);
    }

    ReceiverPreferences(const ReceiverPreferences &receiverPreferencesToCopy) : _probabilityTable(receiverPreferencesToCopy._probabilityTable),
                        _drawnNumberVector(receiverPreferencesToCopy._drawnNumberVector), SUM_OF_PROBABILITIES(receiverPreferencesToCopy.SUM_OF_PROBABILITIES)
    {}
    //returnes values for the map - probability distribution
    std::vector<double> distribution();

    //generates single random number
    double drawNumber();

    //returnes drawn receiver
    IPackageReceiver* drawReceiver();

    void addReceiver(IPackageReceiver* receiver);
    void deleteReceiver(IPackageReceiver* receiver);

    //metody tylko do odczytu
    const_iterator cbegin() const;
    const_iterator cend() const;
    iterator begin();
    iterator end();

};



#endif //NETSIM_RECEIVERPREFERENCES_H
