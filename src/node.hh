#ifndef _NODE_HH_
#define _NODE_HH_

#include <string>
#include <functional>

#include "perf-metric.hh"

class Node : public PerfMetric
{
public:
    Node() : value(""){}
    Node(std::string &data) : value(data){}
    std::string value;
        
    friend std::ostream & operator << (std::ostream &out, const Node &c);
};



#endif