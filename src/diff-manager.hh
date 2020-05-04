#ifndef _DIFF_MANAGER_
#define _DIFF_MANAGER_

#include <string>
#include <vector>

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
    DiffManager(char**programArgs);

private:
    void StartComparison();

};

#endif