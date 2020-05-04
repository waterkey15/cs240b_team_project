#include "binary-search.hh"

BinarySearch::BinarySearch(vector<Node> &source) : Search(source)
{
    cout << "BinarySearch algorithm is setting up..." << endl;
    sort(data.begin(),data.end());//todo: add time and space complexity
    PerfMetric::IncrementOp(data.size());
    // for(auto record& : data){
    //     // operationCount+=record. //todo: count pernode comprasion
    // }
}

