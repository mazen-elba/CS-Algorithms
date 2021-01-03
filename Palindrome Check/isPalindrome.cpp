#include <string>
using namespace std;

bool isPalindrome(string str)
{
    string reversedString = "";
    for (int c = str.length() - 1; c >= 0; c--)
    {
        reversedString += str[c];
    }
    return str == reversedString;
}
