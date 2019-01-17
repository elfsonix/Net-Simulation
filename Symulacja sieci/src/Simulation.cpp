//
// Created by Kasia on 2019-01-15.
//
#include "Simulation.hpp"

int simulate(IReportNotifier* reportNotifier, Factory factory, int numberOfRounds){

 for(int i = 1; i <= numberOfRounds; i++){

//dostawa półproduktów do ramp
    std::for_each(factory._ramps.begin(), factory._ramps.end(), generatePackage());

//przekazanie do odbiorcy
    std::for_each(factory._ramps.begin(), factory._ramps.end(), passPackageToReceiver());

//przetworzenie półproduktów przez robotników
    std::for_each(factory._workers.begin(), factory._workers.end(), putPackageInQueue(*_packageQueue));

    bool generateOrNot = reportNotifier.should_generate_report();
    if(generateOrNot){
    generate_simulation_turn_report()
    }
}



}
