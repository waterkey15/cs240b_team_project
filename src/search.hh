#ifndef _SEARCH_HH_
#define _SEARCH_HH_

#include <vector>
#include <iostream>
#include "node.hh"

using namespace std;

class Search
{
public:
    Search();
    Search(vector<Node>& data);    
    virtual bool Exist(std::string key);
    virtual Node Find(std::string key);
private:
    virtual void AddItem(Node item);
    vector<Node> data;
};

#endif