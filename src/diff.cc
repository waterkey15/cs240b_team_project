#include <iostream>
#include "diff-manager.hh"


int main(int argc, const char** argv) {
    std::unique_ptr<DiffManager> diffManager = std::make_unique<DiffManager>(argc,argv);
    diffManager->PrintPerformanceBenchmarks();
    return 0;
}