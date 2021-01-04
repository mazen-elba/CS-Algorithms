#include <vector>

using namespace std;

string runLengthEncoding(string str) {
	vector<char> encodedChars;
	int currentRunLength = 1;

	for (int i = 1; i < str.size(); i++) {
		char currentChar = str[i];
		char prevChar = str[i - 1];

		if (currentChar != prevChar || currentRunLength == 9) {
			encodedChars.push_back(to_string(currentRunLength)[0]);
			encodedChars.push_back(prevChar);
			currentRunLength = 0;
		}

		currentRunLength++;
	}

	encodedChars.push_back(to_string(currentRunLength)[0]);
	encodedChars.push_back(str[str.size() - ]);

	string encodedString(encodedChars.begin(), encodedChars.end());

	return encodedString;
}
