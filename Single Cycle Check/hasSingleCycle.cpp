#include <vector>
using namespace std;

int nextIdx(int startingIdx, vector<int> array);

bool hasSingleCycle(vector<int> array)
{
    int elementsVisited = 0;
    int startingIdx = 0;
    while (elementsVisited < array.size())
    {
        if (elementsVisited > 0 && startingIdx == 0)
        {
            return false;
        }
        elementsVisited++;
        startingIdx = nextIdx(startingIdx, array);
    }
    return startingIdx == 0;
}

int nextIdx(int startingIdx, vector<int> array)
{
    int jump = array[startingIdx];
    int nextIdx = (startingIdx + jump) % (int)array.size();
    return nextIdx >= 0 ? nextIdx : nextIdx + array.size();
}