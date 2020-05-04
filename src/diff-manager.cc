#include "diff-manager.hh"


DiffManager::DiffManager(std::string fileSource, std::string fileDest, Algo algorithm){
    algorithm = algorithm;
}


DiffManager::DiffManager(const char** programArgs){

}

void DiffManager::StartComparison(){
    std::cout<<"Comparison started"<<std::endl;
}