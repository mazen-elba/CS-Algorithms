#include <any>
#include <vector>

using namespace std;

int productSum(vector<any> array, int multiplier = 1)
{
    int total = 0;
    for (int i = 0; i < array.size(); i++)
    {
        if (array[i].type() == typeid(vector<any>))
        {
            total += productSum(any_cast<vector<any>>(array[i]), multiplier + 1);
        }
        else
        {
            total += any_cast<int>(array[i]);
        }
    }
    return total * multiplier;
}