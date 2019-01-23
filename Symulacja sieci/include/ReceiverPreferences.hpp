// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Katarzyna Wątorska



#ifndef SYMULACJA_SIECI_RECEIVERPREFERENCES_HPP
#define SYMULACJA_SIECI_RECEIVERPREFERENCES_HPP

#include <map>
#include <functional>
#include <cstdlib>
#include <stdexcept>
#include <random>
#include <iostream>
#include "IPackageQueue.hpp"
#include "IPackageReceiver.hpp"
#include <utility>

using preferences_t = std::map<IPackageReceiver*, std::pair<double, double>>;
using vector_p = std::vector<std::pair<IPackageReceiver*, std::pair<double, double>>>;
using const_iterator = preferences_t::const_iterator;
using iterator = preferences_t::iterator;
using pair_double_vector =  std::vector<std::pair<double, double>>;
using double_pair = std::pair<double, double>;

float const SUM_OF_PROBABILITIES = 1.0;

class ReceiverPreferences {
private:
    preferences_t _probabilityTable;
    std::function<double()> _drawnProbability;    //zwraca 1 wartość

    std::vector<IPackageReceiver*> _tempPackageReceiversVector;

    //funkcje pomocnicze dla konstruktora - zwraca wektor par (wskaźnik na odbiorcę, prawdopodobieństwa)
    vector_p convertToVector(std::vector<IPackageReceiver*> packageVector, pair_double_vector doubleVector);
    preferences_t convertToMap(vector_p pairVector);

    //returns values for the map - probability distribution
    pair_double_vector distribution();




public:
    ReceiverPreferences(std::vector<IPackageReceiver*> packageReceiversVector,
                        std::function<double()> drawnProbability);

    ReceiverPreferences(const ReceiverPreferences &receiverPreferencesToCopy) : _probabilityTable(receiverPreferencesToCopy._probabilityTable),
                                                                                _drawnProbability(receiverPreferencesToCopy._drawnProbability),
                                                                                _tempPackageReceiversVector(receiverPreferencesToCopy._tempPackageReceiversVector)
    {}
    std::vector<IPackageReceiver*> getVectorOfReceiver() const;
    //returns drawn receiver
    IPackageReceiver* drawReceiver();
    //generates single random number
    static double drawNumber(); //not to use in tests
    void addReceiver(IPackageReceiver* receiver);
    void deleteReceiver(IPackageReceiver* receiver);

    //metody tylko do odczytu
    const_iterator cbegin() const;
    const_iterator cend() const;
    iterator begin();
    iterator end();

};
#endif
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)