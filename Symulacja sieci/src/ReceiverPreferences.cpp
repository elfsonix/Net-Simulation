// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Katarzyna Wątorska


#include "ReceiverPreferences.hpp"


vector_p ReceiverPreferences::convertToVector(std::vector<IPackageReceiver*> packageVector, std::vector<double> doubleVector){
    vector_p returned;
    std::size_t lengthPackage = packageVector.size();
    std::size_t lengthDouble = doubleVector.size();
    try {
        if(lengthDouble != lengthPackage)
            throw std::invalid_argument("Vectors do not have the same length!");
    }
    catch(std::invalid_argument &ia){
        std::cout<< "Invalid argument: " << ia.what() << std::endl;
    }
    for(std::size_t i = 0; i < lengthDouble; i++){
        auto thing1 = packageVector[i];
        auto thing2 = doubleVector[i];
        returned.push_back(std::make_pair(thing1, thing2));
    }
    return returned;
}

preferences_t ReceiverPreferences::convertToMap(vector_p pairVector){
    preferences_t mapToReturn;

    std::copy(pairVector.begin(), pairVector.end(),
              std::inserter(mapToReturn, mapToReturn.begin()));
    return mapToReturn;
}

std::vector<double> ReceiverPreferences::distribution(){
    std::size_t n = _tempPackageReceiversVector.size();
    float length;
    length = SUM_OF_PROBABILITIES / (float)n;

    // tworzenie dystrybuanty rozkładu dyskretnego
    std::vector<double> probability;
    for (std::size_t i = 1; i <= n; i++){
        probability.push_back(0 + i * length);
    }
    return probability;
}

double ReceiverPreferences::drawNumber() {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen);
}

IPackageReceiver* ReceiverPreferences::drawReceiver(){
/*    std::vector<double> probabilityDistribution = distribution();
    std::vector<IPackageReceiver*> newVector;
    preferences_t::iterator it = _probabilityTable.begin();
    while (it != _probabilityTable.end())
    {
        newVector.push_back(it->first);
    }
    vector_p ve = convertToVector(newVector, probabilityDistribution);
    preferences_t mapka = convertToMap(ve);*/

    preferences_t::iterator iter = _probabilityTable.end()--;
    double drawn = _drawnProbability();
    while (iter != _probabilityTable.begin())
    {
        double value = iter->second;
        if(drawn ???? value){
            return iter->first;
        }
        --iter;
    }
    return iter->first;
}

void ReceiverPreferences::addReceiver(IPackageReceiver* receiver){
    _probabilityTable.insert(std::make_pair(receiver, 0));
    std::vector<double> newDistribution = distribution();
    std::vector<IPackageReceiver*> newVector;
    preferences_t::iterator it = _probabilityTable.begin();
    while (it != _probabilityTable.end())
    {
        newVector.push_back(it->first);
    }
    vector_p vectorToConvert = convertToVector(newVector, newDistribution);
    preferences_t newMap = convertToMap(vectorToConvert);
    _probabilityTable = newMap;

}
void ReceiverPreferences::deleteReceiver(IPackageReceiver* receiver){}

const_iterator ReceiverPreferences::cbegin() const { return _probabilityTable.cbegin(); }
const_iterator ReceiverPreferences::cend() const { return _probabilityTable.cend(); }
iterator ReceiverPreferences::begin() { return _probabilityTable.begin(); }
iterator ReceiverPreferences::end() { return _probabilityTable.end(); }

// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)