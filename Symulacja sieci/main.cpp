#include <iostream>

int main(){

    /*try{
        Factory factory = load_factory_structure(std::istream& stream);

    }
    catch(sommeParseError){
        std::cout<< "There was an error in loading structure from the file.";
    }

    std::cout<< "Structure of factory has been successfully loaded! A report has been generated. :)" << std::endl;
    generate_structure_report();

    //menu dla użytkownika
    std::cout<< "Do you want to modify the structure of the network? \n If no, press 'n'. If yes: \n press"
                "'a' if you want to add a node, \n press 'd' if you want to delete a node."<<std::endl;

    modifyNetwork();
    if(factory.isCompatible()){
        std::cout<< " Network is coherent, you can process to simulation."<<endl;
    }
    else{
        std::cout<<"Network is not coherent :( You have to modify it." <<std::endl;
        modifyNetwork();
    }


    return 0;
}

void modifyNetwork(char addOrDelete){
    switch(addOrDelete){
        case 'a':
            std::cout<<"If you want to add a ramp, press 'r' \n if you  want to add a ramp, \n press 'w' "
                       "if you want to add a worker, \n press 's' if yuo want to add a storehouse." <<std::endl;
            char choice = std::cin.get();
            switch(choice){
                case 'r':
                    std::cout<<"Enter the ID of the ramp: ";
                    while(1){
                        ElementID enteredID = std::cin.get();
                        if(factory.findRampById(enteredID) == nullptr)
                        {
                            ReceiverPreferences receiverPreferences = ReceiverPreferences(...);
                            factory.addRamp(Ramp(enteredID, receiverPreferences));
                        }
                        else {
                            std::cout<< "Such an ID already exists. Enter another value: "<<std::endl;
                        }
                        break;
                    }
                case 'w':




            }


        case 'd':



    }


*/
}