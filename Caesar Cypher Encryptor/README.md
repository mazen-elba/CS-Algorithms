### Caesar Cipher Encrypter
> Given a non-empty string of lowercase letters and a non-negative integer representing a key, write a function that returns a new string obtained by shifting every letter in the input string by k positions in the alphabet, where k is the key.<br/>
> Note: letters should "wrap" around the alphabet.

### Input
string = "xyz"
key = 2

### Output
"zab"

### Solution
Using the Unicode value of a character as well as the character corresponding to a Unicode value. Use the moduolo operator to handle cases where a letter gets shifted to a position that requires wrapping around the alphabet, and also for cases where the key is very large and causes multiple wrappings around the alphabet.
...
	vector<char> newLetters;
	int newKey = key % 26;

	for (int i = 0; i < str.length(); i++) {
	newLetters.push_back(getNewLetter(str[i], newKey));
	}
	
	return string(newLetters.begin(), newLetters.end());
...

Create a new function that determines which leters the input string's letters should be mapped to (ie; map letters to codes). Associate each leter in the alphabet with a specific number (e.g.; its position in the alphabet), and use that number to determine which letter the input string's letters should be mapped to.
```cpp
char getNewLetter(char letter, int key);

...

char getNewLetter(char letter, int ket) {
	int newLetterCode = letter + key;
	return newLetterCode <= 122 ? newLetterCode : 96 + newLetterCode % 122;
}
```

### Complexity Analysis
O(n) Time | O(n) Space
