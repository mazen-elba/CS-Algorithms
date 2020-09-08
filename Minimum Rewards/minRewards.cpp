#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int minRewards(vector<int> scores)
{
    vector<int> rewards = vector<int>(scores.size(), 1);
    for (int i = 1; i < scores.size(); i++)
    {
        int j = i - 1;
        if (scores[i] > scores[j])
        {
            rewards[i] = rewards[j] + 1;
        }
        else
        {
            while (j >= 0 && scores[j] > scores[j + 1])
            {
                rewards[j] = max(rewards[j], rewards[j + 1] + 1);
                j--;
            }
        }
    }
    return accumulate(rewards.begin(), rewards.end(), 0);
}