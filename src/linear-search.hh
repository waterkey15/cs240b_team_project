#ifndef _LINEAR_SEARCH_HH_
#define _LINEAR_SEARCH_HH_

#include "search.hh"

class LinearSearch : public Search {
     public:
        LinearSearch(vector<Node>& data);
        virtual bool Exist(Node& item) override;
};

#endif