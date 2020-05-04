#ifndef _SEARCH_HH_
#define _SEARCH_HH_

#include <vector>
#include <iostream>
#include "node.hh"
#include <memory>

using namespace std;

class Search
{
public:
    Search();
    Search(vector<Node>& refData);
    virtual bool Exist(string key);
    virtual Node Find(string key);
protected:
    vector<Node> data;
};

#endif