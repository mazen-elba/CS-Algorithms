#include <vector>
using namespace std;

bool isMonotonic(vector<int> array)
{
    bool isIncreasing = true;
    bool isDecreasing = true;
    for (int i = 1; i < array.size(); i++)
    {
        if (array[i] < array[i - 1])
        {
            isIncreasing = false;
        }
        if (array[i] > array[i - 1])
        {
            isDecreasing = false;
        }
    }

    return isIncreasing || isDecreasing;
}