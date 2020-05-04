#include "perf-metric.hh"

PerfMetric::PerfMetric()
{
    operationCount = 0;
    compareCount = 0;
    space = 0;
}

PerfMetric::PerfMetric(char* buffer)
{
    operationCount = 0;
    compareCount = 0;
    space = 0;
    printBuffer = buffer;

}

void PerfMetric::PrintPerformanceMetrics()
{
    if (printBuffer == NULL)
    {
        cout << "Printing is not available for this instance!" << endl;
    }else
    {
        sprintf(printBuffer, "%8s %20s\n", "Op Count","Time (Micro Seconds)");
        cout << printBuffer;
        sprintf(printBuffer, "%8d %20d\n", operationCount,elapsedMicroSeconds);
        cout << printBuffer;
    }   
   
}

void PerfMetric::IncrementOp(int size)
{
    operationCount += size;
}

int PerfMetric::GetOpCount(){
    return operationCount;
}

void PerfMetric::MergeMetrics(PerfMetric &metrics)
{
    compareCount += metrics.compareCount;
    operationCount += metrics.operationCount;
    space += metrics.space;
}

void PerfMetric::SetTime(unsigned int time){
    elapsedMicroSeconds = time;
}

