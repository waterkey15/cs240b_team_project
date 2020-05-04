#ifndef _PERF_METRIC_HH
#define _PERF_METRIC_HH

#include <iostream>
#include <memory>

using namespace std;

class PerfMetric{
    public:
        PerfMetric();   
        PerfMetric(char* printBuffer);      
        void PrintPerformanceMetrics();  
        void IncrementOp(int size);
        int GetOpCount();
        void MergeMetrics(PerfMetric& metrics);
        void SetTime(unsigned int timeinMS);
        void SetInputCount(int sourceSize, int compareSize,int foundSize,int notFoundSize);
    protected:
        char* printBuffer;
        int operationCount;
        int compareCount;
        int space;
        int sourceDomainSize,compareDomainSize,foundSize,notFoundSize;
        unsigned int elapsedMicroSeconds;
};
#endif