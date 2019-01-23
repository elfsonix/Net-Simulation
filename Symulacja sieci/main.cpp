// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Katarzyna Wątorska
#include <iostream>
#include "Factory.hpp"
#include "PackageQueue.hpp"
#include "ReceiverPreferences.hpp"
#include "Storehouse.hpp"
#include "Worker.hpp"
#include "DrawNumber.h"

#include "factory_IO.hpp"



int main(){


    try{
        Factory factory = load_factory_structure("struct-input.txt");

    }
    catch(std::runtime_error& runtime_error){
        std::cout<< "There was an error in loading structure from the file.";
    }

    std::cout<< "Structure of factory has been successfully loaded! A report has been generated. :)" << std::endl;
    void generate_structure_report(const Factory& factory, std::ostream& os);
    //menu dla użytkownika
    std::cout<< "Do you want to modify the structure of the network? \n If no, press 'n'. If yes, press 'y'."<<std::endl;
    switch(std::cin.get()){

            case 'y':
            {
            std::vector<IPackageReceiver*> packageReceiversVector;

            Package pack1 = Package();
            Package pack2 = Package();
            Package pack3 = Package();
            std::deque<Package> que;
            que.push_back(pack1);
            que.push_back(pack2);
            std::deque<Package> que2;
            que2.push_back(pack1);
            que2.push_back(pack2);
            PackageQueue packageQueueLIFO = PackageQueue(QueueType::LIFO, que);
            PackageQueue packageQueueFIFO = PackageQueue(QueueType::FIFO, que2);

            PackageQueue packageQueueFIFO2 = PackageQueue(QueueType::FIFO, que2);
            PackageQueue packageQueueLIFO2 = PackageQueue(QueueType::LIFO, que);
            std::unique_ptr<IPackageStockpile> ptr1 = std::make_unique<PackageQueue>(packageQueueLIFO);
            std::unique_ptr<IPackageStockpile> ptr2 = std::make_unique<PackageQueue>(packageQueueFIFO);
            std::unique_ptr<IPackageStockpile> ptr3 = std::make_unique<PackageQueue>(packageQueueFIFO2);
            std::unique_ptr<IPackageStockpile> ptr4 = std::make_unique<PackageQueue>(packageQueueLIFO2);

            Storehouse storehouse1 = Storehouse(10, std::move(ptr1));
            Storehouse storehouse2 = Storehouse(11, std::move(ptr2));
            packageReceiversVector.push_back(&storehouse1);
            packageReceiversVector.push_back(&storehouse2);

            //std::unique_ptr<IPackageStockpile> ptr1 = std::make_unique<PackageQueue>(packageQueueLIFO);
            //std::unique_ptr<IPackageStockpile> ptr2 = std::make_unique<PackageQueue>(packageQueueFIFO);
            //Storehouse storehouse1 = Storehouse(10, std::move(ptr1));
            //Storehouse storehouse2 = Storehouse(11, std::move(ptr2));
            packageReceiversVector.push_back(&storehouse1);
            packageReceiversVector.push_back(&storehouse2);
            std::function<double()> function1 = ([](){return 0.45;});
            //ReceiverPreferences receiverPreferences1 = ReceiverPreferences(packageReceiversVector, drawNumber());
            ReceiverPreferences receiverPreferences1 = ReceiverPreferences(packageReceiversVector,
                                                                                     ReceiverPreferences::drawNumber);
            Worker worker1 = Worker(23, 1,std::make_unique<PackageQueue>(packageQueueFIFO2), receiverPreferences1);

            packageReceiversVector.push_back(&worker1);
            std::function<double()> drawnProbability;
            //const ReceiverPreferences &receiverPreferences =
            factory.addRamp(Ramp(103, 3, receiverPreferences1));



            //Worker worker4 = Worker(20, 2, std::make_unique<PackageQueue>(packageQueueFIFO), receiverPreferences1);

            packageReceiversVector.push_back(&worker1);
            const ReceiverPreferences receiverPreferences2  = ReceiverPreferences(packageReceiversVector,
                                                                           ReceiverPreferences::drawNumber);

            Worker worker2 = Worker(21, 1, std::make_unique<PackageQueue>(packageQueueLIFO2), receiverPreferences2);
            factory.addWorker(worker1);
            factory.addWorker(worker2);
            factory.addStorehouse(storehouse1);
            factory.addStorehouse(storehouse2);
            factory.addRamp(Ramp(30, 1, receiverPreferences1));
            factory.addRamp(Ramp(31, 1, receiverPreferences2));

            std::cout << "Network structure has been modified and saved." << std::endl;
                    save_factory_structure(&factory);

            break;
        }
        default: {
            std::cout << "Network structure was not modified." << std::endl;
            break;
        }
    }

    try{
        factory.isCompatible();
    }
    catch(notCompatibleError){
        std::cout<<"Network is not coherent :( You cannot process to simulation." <<std::endl;
    }

    std::cout<< " Network is coherent, you can process to simulation."<<std::endl;

    std::cout <<"Enter the number fo rounds of simulation: ";
    int numberOfRounds = std::cin.get();
    simulate(IRepoertNotifier, factory, numberOfRounds);
    std::cout << "Simulation has ended! :)"<<std::endl;


    return 0;
}


// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)