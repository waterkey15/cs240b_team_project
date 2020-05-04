#include "binary-search.hh"

BinarySearch::BinarySearch(vector<Node> &source) : Search(source)
{
    cout << "BinarySearch algorithm is setting up..." << endl;
    sort(data.begin(), data.end()); //todo: add time and space complexity
    IncrementOp(data.size());
    for (auto &record : data)
    {
        IncrementOp(record.GetOpCount());
    }
}

bool BinarySearch::Exist(Node &item)
{
    // bool result = std::binary_search(data.begin(),data.end(),item);
    int lowerBound = 0;
    int upperBound = data.size() - 1;
    int midPoint = -1;
    int index = -1;

    while (lowerBound <= upperBound)
    {
        IncrementOp(1);

        midPoint = lowerBound + (upperBound - lowerBound) / 2;

        // data found
        if (data[midPoint].value == item.value)
        {
            index = midPoint;
            return true;
        }
        else
        {
            // if data is larger
            if (data[midPoint].value < item.value)
            {
                // data is in upper half
                lowerBound = midPoint + 1;
            }
            // data is smaller
            else
            {
                // data is in lower half
                upperBound = midPoint - 1;
            }
        }
    }
    return false;
}
