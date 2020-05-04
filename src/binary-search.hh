#ifndef _BINARY_SEARCH_HH_
#define _BINARY_SEARCH_HH_

#include "search.hh"
#include <memory>
#include "node.hh"
#include <vector>
#include <iostream>
#include <algorithm>

class BinarySearch : public Search {
    
    public:
        BinarySearch(vector<Node>& data);
    
};

#endif