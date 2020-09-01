#include <string>
using namespace std;

bool isPalindrome(string str)
{
    string reversedString = "";
    for (int i = str.length() - 1; i >= 0; i--)
    {
        reversedString += str[i];
    }
    return str == reversedString;
}
