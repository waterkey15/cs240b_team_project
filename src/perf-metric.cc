#include "perf-metric.hh"

PerfMetric::PerfMetric()
{
    operationCount = 0;
    compareCount = 0;
    space = 0;
}

void PerfMetric::PrintPerformanceMetrics()
{
    sprintf(printBuffer, "%8s\n", "Op Count");
    cout << printBuffer;
    sprintf(printBuffer, "%8d\n", operationCount);
    cout << printBuffer;
}

void PerfMetric::IncrementOp(int size)
{
    operationCount += size;
}
