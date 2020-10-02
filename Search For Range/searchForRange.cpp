#include <vector>
using namespace std;

vector<int> searchForRange(vector<int> array, int target);
void helperFx(vector<int> array, int target, int leftIdx, int rightIdx, vector<int> *finalRange, bool goLeft);

vector<int> searchForRange(vector<int> array, int target)
{
    vector<int> finalRange{-1, -1};
    helperFx(array, target, 0, array.size() - 1, &finalRange, true);
    helperFx(array, target, 0, array.size() - 1, &finalRange, false);
    return finalRange;
}

// Variation of Binary Search Algorithm
void helperFx(vector<int> array, int target, int leftIdx, int rightIdx, vector<int> *finalRange, bool goLeft)
{
    while (leftIdx <= rightIdx)
    {
        int midIdx = (leftIdx + rightIdx) / 2;
        if (array[midIdx] < target)
        {
            leftIdx = midIdx + 1;
        }
        else if (array[midIdx] > target)
        {
            rightIdx = midIdx - 1;
        }
        else
        {
            if (goLeft)
            {
                if (midIdx == 0 || array[midIdx - 1] != target)
                {
                    finalRange->at(0) = midIdx;
                    return;
                }
                else
                {
                    rightIdx = midIdx - 1;
                }
            }
            else
            {
                if (midIdx == array.size() - 1 || array[midIdx + 1] != target)
                {
                    finalRange->at(1) = midIdx;
                    return;
                }
                else
                {
                    leftIdx = midIdx + 1;
                }
            }
        }
    }
}