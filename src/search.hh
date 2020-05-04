#ifndef _SEARCH_HH_
#define _SEARCH_HH_

#include <vector>
#include <iostream>
#include "node.hh"
#include <memory>
#include "perf-metric.hh"

using namespace std;

class Search : public PerfMetric
{
public:
    Search();
    Search(vector<Node>& refData);
    virtual bool Exist(Node& item);
    void PrintData();
protected:
    vector<Node> data;
};

#endif