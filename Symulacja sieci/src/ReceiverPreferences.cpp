// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Katarzyna Wątorska


#include "ReceiverPreferences.hpp"


std::vector<std::pair<IPackageReceiver*, std::pair<double, double>>> ReceiverPreferences::convertToVector(std::vector<IPackageReceiver*> packageVector, std::vector<std::pair<double, double>> doubleVector){
    std::vector<std::pair<IPackageReceiver*, std::pair<double, double>>> returned;
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
        IPackageReceiver* thing1 = packageVector[i];
        std::pair<double, double> thing2 = doubleVector[i];
        returned.push_back(std::make_pair(thing1, thing2));
    }
    return returned;
}

preferences_t ReceiverPreferences::convertToMap(vector_p pairVector){
    preferences_t mapToReturn;
    for (auto each : pairVector){
        IPackageReceiver* one = each.first;
        std::pair<double, double> two = each.second;
        mapToReturn.insert(std::make_pair(one, two));

    }
    return mapToReturn;
}

std::vector<std::pair<double, double>> ReceiverPreferences::distribution(){
    std::size_t n = _tempPackageReceiversVector.size();
    float length;
    length = SUM_OF_PROBABILITIES / (float)n;

    // tworzenie dystrybuanty rozkładu dyskretnego
    std::vector<std::pair<double, double>> probability;
    for (std::size_t i = 1; i <= n; i++){
        std::pair<double, double> pairToAdd = std::make_pair(0+(i-1)*length, 0 + i * length);
        probability.push_back(pairToAdd);
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
    preferences_t::iterator iter = _probabilityTable.begin();
    double drawn = _drawnProbability();
    while (iter != _probabilityTable.end())
    {
        std::pair<double, double> value = iter->second;
        double lowerBound = value.first;
        double upperBound = value.second;

        if(drawn >= lowerBound && drawn < upperBound){
            return iter->first;
        }
        iter++;
    }
    return iter->first;
}

void ReceiverPreferences::addReceiver(IPackageReceiver* receiver){
    _tempPackageReceiversVector.push_back(receiver);
    std::vector<std::pair<double, double>> newDistribution = distribution();


    std::vector<std::pair<IPackageReceiver*, std::pair<double, double>>> vectorToConvert = convertToVector(_tempPackageReceiversVector, newDistribution);
    _probabilityTable  = convertToMap(vectorToConvert);
}
void ReceiverPreferences::deleteReceiver(IPackageReceiver* receiver){
    _tempPackageReceiversVector.erase(std::find(_tempPackageReceiversVector.begin(),_tempPackageReceiversVector.end(),receiver));

    std::vector<std::pair<double, double>> newDistribution = distribution();


    std::vector<std::pair<IPackageReceiver*, std::pair<double, double>>> vectorToConvert = convertToVector(_tempPackageReceiversVector, newDistribution);
    _probabilityTable  = convertToMap(vectorToConvert);
}


const_iterator ReceiverPreferences::cbegin() const { return _probabilityTable.cbegin(); }
const_iterator ReceiverPreferences::cend() const { return _probabilityTable.cend(); }
iterator ReceiverPreferences::begin() { return _probabilityTable.begin(); }
iterator ReceiverPreferences::end() { return _probabilityTable.end(); }

// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)