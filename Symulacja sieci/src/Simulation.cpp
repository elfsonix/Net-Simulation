/*
//
// Created by Kasia on 2019-01-15.
//
#include "Factory.hpp"
#include "Simulation.hpp"

int simulate(IReportNotifier* reportNotifier, Factory factory, int numberOfRounds){

 for(int i = 1; i <= numberOfRounds; i++){

   //dostawa półproduktów do ramp
   for(auto ramp : getRampsList()){
      ramp.generatePackage(1); //częstotliwość generowania paczki zawsze 1... :/
   }
   // std::for_each(factory._ramps.begin(), factory._ramps.end(), generatePackage(2));

   //przekazanie do odbiorcy
    for(auto ramp : getRampsList()){
       ramp.passPackageToReceiver();
    }
    //std::for_each(factory._ramps.begin(), factory._ramps.end(), passPackageToReceiver());

    //przetworzenie półproduktów przez robotników
    for(auto worker : getWorkersList()){
       worker.putPacakgeInQueue(????);
    }
    //std::for_each(factory._workers.begin(), factory._workers.end(), putPackageInQueue(*_packageQueue));

    if(reportNotifier.should_generate_report()){
         generate_simulation_turn_report()
    }
    generate_structure_raport();
}



}
*/
