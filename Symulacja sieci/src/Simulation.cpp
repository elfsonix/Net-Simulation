// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Katarzyna Wątorska
#include "Factory.hpp"
#include "Simulation.hpp"
#include "reporting.hpp"

void simulate(IReportNotifier* reportNotifier, Factory factory, int numberOfRounds){
   // std::ostream os;

 for(int i = 1; i <= numberOfRounds; i++){

   //dostawa półproduktów do ramp
   for(auto iter = factory.getRampB(); iter != factory.getRampE(); iter++){
      iter->generatePackage(1); //częstotliwość generowania paczki zawsze 1... :/
   }

   //przekazanie do odbiorcy
    for(auto iter = factory.getRampB(); iter != factory.getRampE(); iter++){
       iter->passPackageToReceiver();
    }

    //przetworzenie półproduktów przez robotników i ewentualne przekazanie paczki
    for(auto it = factory.getWorkerB(); it != factory.getWorkerE(); it++){
       it->processPackage();
    }


    if(reportNotifier->should_generate_report(i)){

        //generate_simulation_turn_report(&factory, os, i);
    }
     //generate_structure_report(&factory, os);
}

}
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
