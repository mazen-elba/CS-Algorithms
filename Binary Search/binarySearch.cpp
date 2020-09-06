#include <vector>
using namespace std;

int binarySearch(vector<int> array, int target);

int binarySearch(vector<int> array, int target)
{
    int leftIdx = 0;
    int rightIdx = array.size();
    while (leftIdx <= rightIdx)
    {
        int middleIdx = (leftIdx + rightIdx) / 2;
        int potentialMatch = array[middleIdx];
        if (target == potentialMatch)
        {
            return middleIdx;
        }
        else if (target < potentialMatch)
        {
            rightIdx = middleIdx - 1;
        }
        else
        {
            leftIdx = middleIdx + 1;
        }
    }
    return -1;
}