
//
// Created by Kasia on 2019-01-15.
//
#include "Factory.hpp"
#include "Simulation.hpp"

int simulate(IReportNotifier* reportNotifier, Factory factory, int numberOfRounds){

 for(int i = 1; i <= numberOfRounds; i++){

   //dostawa półproduktów do ramp
   for(auto ramp: factory.getRamps()){
      ramp.generatePackage(1); //częstotliwość generowania paczki zawsze 1... :/
   }

   //przekazanie do odbiorcy
    for(auto ramp : factory.getRamps()){
       ramp.passPackageToReceiver();
    }

    //przetworzenie półproduktów przez robotników i ewentualne przekazanie paczki
    for(auto it = factory.getWorkerB(); it != factory.getWorkerE(); it++){
       it->processPackage();
    }


    if(reportNotifier.should_generate_report()){
         generate_simulation_turn_report()
    }
    generate_structure_raport();
}

}
