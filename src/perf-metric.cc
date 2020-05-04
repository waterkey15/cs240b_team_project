#include "perf-metric.hh"

PerfMetric::PerfMetric()
{
    operationCount = 0;
    compareCount = 0;
    space = 0;
    sourceDomainSize = 0;
    compareDomainSize = 0;
    foundSize=0;
    notFoundSize=0;
}

PerfMetric::PerfMetric(char *buffer)
{
    operationCount = 0;
    compareCount = 0;
    space = 0;
    sourceDomainSize = 0;
    compareDomainSize = 0;
    foundSize=0;
    notFoundSize=0;
    printBuffer = buffer;
}

void PerfMetric::PrintPerformanceMetrics()
{
    if (printBuffer == NULL)
    {
        cout << "\n\nPrinting is not available for this instance!" << endl;
    }
    else
    {
        cout << "\n\n#### Performance Result #####\n\n";
        sprintf(printBuffer, "%9s   %10s   %8s   %20s  %13s  %18s\n", "N (A Src)", "N (B Dest)", "Op Count", "Time (Micro Seconds)","( A∩B ) Found","( A\\B ) Not Found");
        cout << printBuffer;
        sprintf(printBuffer, "%9d   %10d   %8d   %20d  %13d  %18d\n", sourceDomainSize, compareDomainSize, operationCount, elapsedMicroSeconds,foundSize,notFoundSize);
        cout << printBuffer;
    }
}

void PerfMetric::SetInputCount(int sourceSize, int compareSize,int fndSize,int notFndSize)
{
    sourceDomainSize = sourceSize;
    compareDomainSize = compareSize;
    foundSize = fndSize;
    notFoundSize = notFndSize;
}

void PerfMetric::IncrementOp(int size)
{
    operationCount += size;
}

int PerfMetric::GetOpCount()
{
    return operationCount;
}

void PerfMetric::MergeMetrics(PerfMetric &metrics)
{
    compareCount += metrics.compareCount;
    operationCount += metrics.operationCount;
    space += metrics.space;
}

void PerfMetric::SetTime(unsigned int time)
{
    elapsedMicroSeconds = time;
}
