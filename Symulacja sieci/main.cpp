#include <iostream>
#include "Factory.hpp"
#include "PackageQueue.hpp"
#include "ReceiverPreferences.hpp"
#include "Storehouse.hpp"
#include "Worker.hpp"

int main(){
/*
    try{
        Factory factory = load_factory_structure(std::istream & stream);

    }
    catch(sommeParseError){
        std::cout<< "There was an error in loading structure from the file.";
    }

    std::cout<< "Structure of factory has been successfully loaded! A report has been generated. :)" << std::endl;
    generate_structure_report();

    //menu dla użytkownika
    std::cout<< "Do you want to modify the structure of the network? \n If no, press 'n'. If yes, press 'y'."<<std::endl;
    switch(std::cin.get()){
        case 'y':
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
            std::unique_ptr<IPackageStockpile> ptr1 = std::make_unique<PackageQueue>(packageQueueLIFO);
            std::unique_ptr<IPackageStockpile> ptr2 = std::make_unique<PackageQueue>(packageQueueFIFO);
            Storehouse storehouse1 = Storehouse(10, std::move(ptr1));
            Storehouse storehouse2 = Storehouse(11, std::move(ptr2));
            packageReceiversVector.push_back(&storehouse1);
            packageReceiversVector.push_back(&storehouse2);
            std::function<double()> function1 = ([](){return 0.45;});
            ReceiverPreferences receiverPreferences1 = ReceiverPreferences(packageReceiversVector, ReceiverPreferences::drawNumber();
            Worker worker1 = Worker(20, 2, )

            packageReceiversVector.push_back(&worker1);
            std::function<double()> drawnProbability)
            const ReceiverPreferences &receiverPreferences =
            factory.addRamp(Ramp(enteredID, receiverPreferences));

            std::cout << "Network structure has been modified." <<std::endl;
            break;
        default:
            std::cout << "Network structure was not modified." <<std::endl;
            break;
    }




    if(factory.isCompatible()){
        std::cout<< " Network is coherent, you can process to simulation."<<endl;
    }
    else{
        std::cout<<"Network is not coherent :( You have to modify it." <<std::endl;
        modifyNetwork();
    }


    return 0;
}

*/
}