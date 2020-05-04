#ifndef _BINARY_SEARCH_HH_
#define _BINARY_SEARCH_HH_

#include "search.hh"
#include <memory>
#include "node.hh"
#include <vector>
#include <iostream>
#include "math.h"
#include "perf-metric.hh"

class BinarySearch : public Search {
    
    public:
        BinarySearch(vector<Node>& data);
        virtual bool Exist(Node& item) override;
    private:        
        vector<Node> sort(vector<Node> data);
        vector<Node> merge(vector<Node> left, vector<Node> right);
    
};

#endif