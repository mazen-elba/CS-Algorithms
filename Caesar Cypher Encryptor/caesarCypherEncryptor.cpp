#include <string>
#include <vector>
#include <numeric>

using namespace std;

char helper(char letter, int key);

string caesarCypherEncryptor(string str, int key)
{
    vector<char> newLetters;
    int newKey = key % 26;
    for (int i = 0; i < str.length(); i++)
    {
        newLetters.push_back(helper(str[i], newKey));
    }
    return string(newLetters.begin(), newLetters.end());
}

char helper(char letter, int key)
{
    int newLetterCode = letter + key;
    return newLetterCode <= 122 ? newLetterCode : 96 + newLetterCode % 122;
}
