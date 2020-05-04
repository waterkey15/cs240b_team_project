#include <string>
#include <iostream>


int main(int argc, const char** argv) {

    for(int i;i<argc;i++){
        std::cout<< argv[i] << std::endl;
    }
    return 0;
}