// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Katarzyna Wątorska


#include "ReceiverPreferences.hpp"

ReceiverPreferences::ReceiverPreferences(std::vector<IPackageReceiver*> packageReceiversVector,
        std::function<double()> drawnProbability): _drawnProbability(
        std::move(drawnProbability)), _tempPackageReceiversVector(packageReceiversVector){

    double_vector doubleVector = distribution();
    vector_p v = convertToVector(packageReceiversVector, doubleVector);
    _probabilityTable = convertToMap(v);
}

vector_p ReceiverPreferences::convertToVector(std::vector<IPackageReceiver*> packageVector, double_vector doubleVector){
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
        double thing2 = doubleVector[i];
        returned.push_back(std::make_pair(thing1, thing2));
    }
    return returned;
}

preferences_t ReceiverPreferences::convertToMap(vector_p pairVector){
    preferences_t mapToReturn;
    for (auto each : pairVector){
        IPackageReceiver* one = each.first;
        double two = each.second;
        mapToReturn.insert(std::make_pair(one, two));

    }
    return mapToReturn;
}

double_vector ReceiverPreferences::distribution(){
    std::size_t n = _tempPackageReceiversVector.size();
    double length;
    length = SUM_OF_PROBABILITIES / (double)n;
    double_vector probability;
    for(int i = 0; i <n; i++)
        probability.push_back(length);
    return probability;
}

double ReceiverPreferences::drawNumber() {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen);
}

IPackageReceiver* ReceiverPreferences::drawReceiver(){
    double drawn = _drawnProbability();
    std::size_t n = _tempPackageReceiversVector.size();

    // tworzenie dystrybuanty rozkładu dyskretnego
    pair_double_vector probabilityDistribution;

    double_vector mapKeys;
    for(auto elem : _probabilityTable)
        mapKeys.push_back(elem.second);
    double current = 0;
    for (std::size_t i = 1; i <= n; i++){
        double_pair pairToAdd = std::make_pair(current, mapKeys[i]);
        probabilityDistribution.push_back(pairToAdd);
        current += mapKeys[i];
    }
    pair_double_vector::const_iterator iter = probabilityDistribution.cbegin();

    while (iter != probabilityDistribution.end())
    {
        double_pair value = *iter;
        double lowerBound = value.first;
        double upperBound = value.second;

        if(drawn >= lowerBound && drawn < upperBound){
            auto result = std::find_if(_probabilityTable.begin(), _probabilityTable.end(), [this](double_pair value){
                const_iterator iterator1 = _probabilityTable.cbegin();
                if(iterator1->second >= value.first && iterator1->second < value.second){
                    return iterator1->first;
                }
            });
            return result->first;
        }
        iter++;
    }
    return iter->first;
}

void ReceiverPreferences::addReceiver(IPackageReceiver* receiver){
    _tempPackageReceiversVector.push_back(receiver);
    double_vector newDistribution = distribution();


    vector_p vectorToConvert = convertToVector(_tempPackageReceiversVector, newDistribution);
    _probabilityTable  = convertToMap(vectorToConvert);
}
void ReceiverPreferences::deleteReceiver(IPackageReceiver* receiver){
    _tempPackageReceiversVector.erase(std::find(_tempPackageReceiversVector.begin(),_tempPackageReceiversVector.end(),receiver));

    double_vector newDistribution = distribution();


    vector_p vectorToConvert = convertToVector(_tempPackageReceiversVector, newDistribution);
    _probabilityTable  = convertToMap(vectorToConvert);
}


const_iterator ReceiverPreferences::cbegin() const { return _probabilityTable.cbegin(); }
const_iterator ReceiverPreferences::cend() const { return _probabilityTable.cend(); }
iterator ReceiverPreferences::begin() { return _probabilityTable.begin(); }
iterator ReceiverPreferences::end() { return _probabilityTable.end(); }

// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)