#include "search.hh"



Search::Search(vector<Node>& refData){
    data = refData;
}

Search::Search(){}

Node Search::Find(std::string key){return Node();}

bool Search::Exist(std::string key){return false;}