#ifndef _PERF_METRIC_HH
#define _PERF_METRIC_HH

#include <iostream>

using namespace std;

class PerfMetric{
    public:
        PerfMetric();         
        void PrintPerformanceMetrics();  
        void IncrementOp(int size);
    protected:
        char printBuffer [50];
        int operationCount;
        int compareCount;
        int space;
};
#endif