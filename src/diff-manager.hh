#ifndef _DIFF_MANAGER_
#define _DIFF_MANAGER_

#include <string>
#include <vector>
#include <memory>
#include <iostream>

class DiffManager
{

public:
    enum Algo
    {
        BINARYSEARCH,
        LINEARSEARCH
    };
    const Algo algorithm = BINARYSEARCH; //Default Value
    DiffManager(std::string fileSource, std::string fileDest, Algo algorithm);
    DiffManager(const char**programArgs);
    void StartComparison();
private:
    

};

#endif