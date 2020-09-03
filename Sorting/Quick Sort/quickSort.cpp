#include <vector>
using namespace std;

void helperFx(vector<int> &array, int startIdx, int endIdx);

vector<int> quickSort(vector<int> array)
{
    helperFx(array, 0, array.size() - 1);
    return array;
}

void helperFx(vector<int> &array, int startIdx, int endIdx)
{
    if (startIdx >= endIdx)
    {
        return;
    }

    int pivotIdx = startIdx;
    int leftIdx = startIdx + 1;
    int rightIdx = endIdx;
    while (rightIdx >= leftIdx)
    {
        if (array.at(leftIdx) > array.at(pivotIdx) && array.at(rightIdx) < array.at(pivotIdx))
        {
            swap(array[leftIdx], array[rightIdx]);
        }
        if (array.at(leftIdx) <= array.at(pivotIdx))
        {
            leftIdx++;
        }
        if (array.at(rightIdx) >= array.at(pivotIdx))
        {
            rightIdx--;
        }
    }

    swap(array[pivotIdx], array[rightIdx]);
    bool leftSubarrayIsSmaller = (leftIdx - 1 - startIdx) < (endIdx - rightIdx + 1);
    if (leftSubarrayIsSmaller)
    {
        helperFx(array, startIdx, rightIdx - 1);
        helperFx(array, rightIdx + 1, endIdx);
    }
    else
    {
        helperFx(array, rightIdx + 1, endIdx);
        helperFx(array, startIdx, rightIdx - 1);
    }
}