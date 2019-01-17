#include <iostream>

int main(){

    try{
        Factory factory = load_factory_structure(std::istream& stream);

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


}