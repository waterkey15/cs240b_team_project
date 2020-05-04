#ifndef _DIFF_MANAGER_
#define _DIFF_MANAGER_

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "search.hh"
#include "node.hh"
#include <fstream>
#include "binary-search.hh"
#include "linear-search.hh"
#include <stdio.h>
#include "perf-metric.hh"
#include <chrono>

using namespace std;

class DiffManager
{

public:
    enum Algo
    {
        BINARYSEARCH,
        LINEARSEARCH
    };
    DiffManager(string fileSource, string fileDest, Algo algorithm);
    DiffManager(int paramCount,const char**programArgs);
    void PrintPerformanceBenchmarks();
    void StartComparison();
    bool Ready();
    vector<Node> sourceData;
    vector<Node> compareData;
    vector<Node> foundList;
    vector<Node> notFoundList;
    ~DiffManager();
private:
    bool isDataLoaded;
    unique_ptr<Search> compareAlgorithm;  
    fstream sourceFile, compareFile;
    void Load(string fileSource, string fileDest, Algo algorithm);  
    void LoadDataIntoMemory(fstream& source,vector<Node>& refData); 
    unique_ptr<Search> AlgorithmFactory(Algo algorithm);
    PerfMetric metrics;
    char printBuffer[200];   
    unsigned int microSeconds; 
};

#endif