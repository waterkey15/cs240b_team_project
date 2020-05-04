#include "binary-search.hh"

BinarySearch::BinarySearch(vector<Node> &source) : Search(source)
{
    cout << "BinarySearch algorithm is setting up..." << endl;
    data = sort(data); //todo: add time and space complexity
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

vector<Node> BinarySearch::sort(vector<Node> m)
{

    if (m.size() <= 1)
        return m;
    vector<Node> left, right,compareTemp;
    int middle = ((int)m.size() + 1) / 2;

    for (int i = 0; i < middle; i++)
    {
        left.push_back(m[i]);
    }

    for (int i = middle; i < (int)m.size(); i++)
    {
        right.push_back(m[i]);
    }

    left = sort(left);
    right = sort(right);
    compareTemp = merge(left, right);
    return compareTemp;
}

vector<Node> BinarySearch::merge(vector<Node> left, vector<Node> right)
{
    vector<Node> compareTemp;

    while ((int)left.size() > 0 || (int)right.size() > 0)
    {
        if ((int)left.size() > 0 && (int)right.size() > 0)
        {
            IncrementOp(1);
            if (left.front().value <= right.front().value)
            {                
                compareTemp.push_back(left.front());
                left.erase(left.begin());
            }
            else
            {
                compareTemp.push_back(right.front());
                right.erase(right.begin());
            }
        }
        else if ((int)left.size() > 0)
        {
            for (int i = 0; i < (int)left.size(); i++){
                IncrementOp(1);
                compareTemp.push_back(left[i]);
            }                
            break;
        }
        else if ((int)right.size() > 0)
        {
            for (int i = 0; i < (int)right.size(); i++){
                IncrementOp(1);
                compareTemp.push_back(right[i]);
            }
                
            break;
        }
    }
    return compareTemp;
}