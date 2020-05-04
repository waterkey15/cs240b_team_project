#include <iostream>
#include "diff-manager.hh"


int main(int argc, const char** argv) {
    std::unique_ptr<DiffManager> diffManager = std::make_unique<DiffManager>(argc,argv);
    if(!diffManager->Ready()){
        std::cout<<"Data loading error!"<<std::endl;
        return 1;
    }
    diffManager->StartComparison();
    diffManager->PrintPerformanceBenchmarks();
    return 0;
}