#include "binary-search.hh"

BinarySearch::BinarySearch(vector<Node> &source) : Search(source)
{
    cout << "BinarySearch algorithm is setting up..." << endl;
    // sort(data->begin(),data->end());
    cout<<"##### Data ######\n";
      for(int i=0;i<data.size();i++){
        cout<< data.at(i).value << endl;
    }
    cout<<"\n\n";
}