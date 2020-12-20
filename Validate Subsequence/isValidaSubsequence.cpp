#include <vector>
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence)
{
    int arrIdx = 0;
    int seqIdx = 0;
    while (arrIdx < array.size() && seqIdx < sequence.size())
    {
        if (array.at(arrIdx) == sequence.at(seqIdx))
        {
            seqIdx++;
        }
        arrIdx++;
    }

    return seqIdx == sequence.size();
}