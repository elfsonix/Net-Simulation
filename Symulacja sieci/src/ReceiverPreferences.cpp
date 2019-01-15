// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Katarzyna Wątorska


#include "ReceiverPreferences.hpp"

ReceiverPreferences::ReceiverPreferences(std::vector<IPackageReceiver*> packageReceiversVector,
        std::function<double()> drawnProbability): _drawnProbability(
        std::move(drawnProbability)), _tempPackageReceiversVector(packageReceiversVector){

    pair_double_vector doubleVector = distribution();
    vector_p v = convertToVector(packageReceiversVector, doubleVector);
    _probabilityTable = convertToMap(v);
}

vector_p ReceiverPreferences::convertToVector(std::vector<IPackageReceiver*> packageVector, pair_double_vector doubleVector){
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
        IPackageReceiver* thing1 = packageVector[i];
        double_pair thing2 = doubleVector[i];
        returned.push_back(std::make_pair(thing1, thing2));
    }
    return returned;
}

preferences_t ReceiverPreferences::convertToMap(vector_p pairVector){
    preferences_t mapToReturn;
    for (auto each : pairVector){
        IPackageReceiver* one = each.first;
        double_pair two = each.second;
        mapToReturn.insert(std::make_pair(one, two));

    }
    return mapToReturn;
}

pair_double_vector ReceiverPreferences::distribution(){
    std::size_t n = _tempPackageReceiversVector.size();
    float length;
    length = SUM_OF_PROBABILITIES / (float)n;

    // tworzenie dystrybuanty rozkładu dyskretnego
    pair_double_vector probability;
    for (std::size_t i = 1; i <= n; i++){
        double_pair pairToAdd = std::make_pair(0+(i-1)*length, 0 + i * length);
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
    while (iter != _probabilityTable.begin())
    {
       double_pair value = iter->second;
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
    pair_double_vector newDistribution = distribution();


    vector_p vectorToConvert = convertToVector(_tempPackageReceiversVector, newDistribution);
    _probabilityTable  = convertToMap(vectorToConvert);
}
void ReceiverPreferences::deleteReceiver(IPackageReceiver* receiver){
    _tempPackageReceiversVector.erase(std::find(_tempPackageReceiversVector.begin(),_tempPackageReceiversVector.end(),receiver));

    pair_double_vector newDistribution = distribution();


    vector_p vectorToConvert = convertToVector(_tempPackageReceiversVector, newDistribution);
    _probabilityTable  = convertToMap(vectorToConvert);
}


const_iterator ReceiverPreferences::cbegin() const { return _probabilityTable.cbegin(); }
const_iterator ReceiverPreferences::cend() const { return _probabilityTable.cend(); }
iterator ReceiverPreferences::begin() { return _probabilityTable.begin(); }
iterator ReceiverPreferences::end() { return _probabilityTable.end(); }

// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)