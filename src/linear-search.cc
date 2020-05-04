#include "linear-search.hh"

LinearSearch::LinearSearch(vector<Node> &source) : Search(source)
{
    cout << "LinearSearch algorithm is setting up..." << endl;
    IncrementOp(data.size());
}

bool LinearSearch::Exist(Node &item)
{
    for(Node& record:data){
        IncrementOp(1);
        if(item.value==record.value)
            return true;
    }
    return false;
}