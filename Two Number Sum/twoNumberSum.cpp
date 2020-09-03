#include <vector>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum)
{
    for (int i = 0; i < array.size(); i++)
    {
        for (int j = i + 1; j < array.size(); j++)
        {
            if (targetSum == array[i] + array[j])
            {
                return vector<int>{array[i], array[j]};
            }
        }
    }
    return {};
}