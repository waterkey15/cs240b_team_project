#include "diff-manager.hh"

DiffManager::DiffManager(string fileSourcePath, string fileToComparePath, Algo algo)
{
    Load(fileSourcePath, fileToComparePath, algo);
}

void DiffManager::Load(string fileSourcePath, string fileToComparePath, Algo algorithm)
{
    metrics = PerfMetric(printBuffer);
    sourceFile.open(fileSourcePath);
    compareFile.open(fileToComparePath);

    if (!sourceFile.is_open())
    {
        cout << "Source file couldn't open!" << endl;
        return;
    }
    if (!compareFile.is_open())
    {
        cout << "Compare file couldn't open!" << endl;
        return;
    }
    LoadDataIntoMemory(sourceFile, sourceData);
    LoadDataIntoMemory(compareFile, compareData);
    isDataLoaded = true;
    compareAlgorithm = AlgorithmFactory(algorithm);
}

DiffManager::~DiffManager()
{
    sourceData.clear();
    compareData.clear();
    sourceFile.close();
    compareFile.close();
}

DiffManager::DiffManager(int paramCount, const char **programArgs)
{
    if (paramCount < 3)
    {
        cout << "Invalid parameters.\n./app <sourcefile> <destfile> 'B|L'" << endl;
    }
    else
    {
        for (int i = 0; i < paramCount; i++)
        {
            cout << programArgs[i] << endl;
        }
        char algoParam = programArgs[3][0];

        if (algoParam == 'B' || algoParam == 'b')
            Load(programArgs[1], programArgs[2], Algo::BINARYSEARCH);
        else if (algoParam == 'L' || algoParam == 'l')
            Load(programArgs[1], programArgs[2], Algo::LINEARSEARCH);
        else
            Load(programArgs[1], programArgs[2], Algo::BINARYSEARCH);
    }
}

void DiffManager::LoadDataIntoMemory(fstream &source, vector<Node> &refData)
{
    std::string line;
    while (getline(source, line))
    {
        if (line.size() > 0)
            refData.push_back(Node(line));
    }
}

unique_ptr<Search> DiffManager::AlgorithmFactory(Algo algorithm)
{
    cout << "Algorithm factory" << endl;
    std::unique_ptr<Search> runtimeSearch;
    switch (algorithm)
    {
    case BINARYSEARCH:
        runtimeSearch = std::make_unique<BinarySearch>(compareData);
        break;
    case LINEARSEARCH:
        runtimeSearch = std::make_unique<LinearSearch>(compareData);
        break;
    default:
        runtimeSearch = std::make_unique<BinarySearch>(compareData);
        break;
    }
    return runtimeSearch;
}

bool DiffManager::Ready()
{
    return isDataLoaded;
}

void DiffManager::StartComparison()
{
    cout << "Comparison started" << endl;
    auto start = chrono::steady_clock::now();
    for(Node& record:sourceData){
        if(compareAlgorithm->Exist(record)){
            foundList.push_back(record);
        }else{
            notFoundList.push_back(record);
        }
    }
    auto end = chrono::steady_clock::now();
    microSeconds=chrono::duration_cast<chrono::microseconds>(end - start).count();
    metrics.SetTime(microSeconds);
}

void DiffManager::PrintPerformanceBenchmarks()
{
    metrics.SetInputCount(sourceData.size(),compareData.size(),foundList.size(),notFoundList.size());
    metrics.IncrementOp(compareAlgorithm->GetOpCount());    
    metrics.PrintPerformanceMetrics();
}