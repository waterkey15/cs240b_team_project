#include <iostream>
#include "diff-manager.hh"


int main(int argc, const char** argv) {

    for(int i;i<argc;i++){
        std::cout<< argv[i] << std::endl;
    }
    std::unique_ptr<DiffManager> diffManager = std::make_unique<DiffManager>(argv);
    diffManager->StartComparison();
    return 0;
}