#ifndef _SEARCH_HH_
#define _SEARCH_HH_

#include <vector>
#include <iostream>
#include "binary-search.hh"
#include "node.hh"

using namespace std;

template<class T>
class Search
{
public:
    Search();
    Search(vector<T> data);
    virtual void AddItem(T item);
    virtual bool Exist(std::string key);
    virtual T Find(std::string key);
private:
    vector<T> data;
};

#endif