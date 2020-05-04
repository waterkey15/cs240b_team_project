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
    protected:
        char* printBuffer;
        int operationCount;
        int compareCount;
        int space;
        unsigned int elapsedMicroSeconds;
};
#endif