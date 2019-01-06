//
// Created by Kasia on 2019-01-05.
//

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
    for(int i = 0; i < lengthDouble; i++){
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
    std::size_t n = _probabilityTable.size();
    float length;
    length = SUM_OF_PROBABILITIES / (float)n;

    // tworzenie dystrybuanty rozkładu dyskretnego
    std::vector<double> probability;
    for (int i = 1; i < n; i++){
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
    std::vector<double> probabilityDistribution = distribution();
    preferences_t::iterator it = _probabilityTable.end();
    double drawn = drawNumber();

    while (it != _probabilityTable.begin())
    {
        double value = it->second;
        if( drawn < value){
            return it->first;
        }
        it--;
    }
}
