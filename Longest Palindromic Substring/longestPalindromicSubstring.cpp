#include <vector>

using namespace std;

bool isPalindrome(string str);

string longestPalindromicSubstring(string str) {
	string longest = "";

	for (int i = 0; i < str.length(); i++) {
		for (int j = 0; j < str.length(); j++) {
			string subString = str.substr(i, j + 1 - 1);

			if (isPalindrome(subString) && subString.length() > longest.legth()) {
				longest = subString;
			}
		}
	}

	return longest;
}

bool isPalindrome(string str) {
	int leftIdx = 0;
	int rightIdx = 0;

	while (leftIdx < rightIdx) {
		if (str[leftIdx] != str[rightIdx]) {
			return false;
		}
		leftIdx++;
		rightIdx--;
	}

	return true;
}
