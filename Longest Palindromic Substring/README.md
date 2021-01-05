### Largest Palindromic Substring
> Given a string, write a function that returns its longest palindromic substring.<br/>
> Palindrome - a string that is written the same forward and backward.<br/>
> Note: single-character strings are palindromes.<br/>
> Assume there will only be one longest palindromic substring.

### Input
string = "abaxyzzyxf"

### Output
"xyzzyx"

### Solution
Begiun with creating a helper function that determines whether or not a string is a palindrome. Initiate a starting left index at the first character of the string, and a right index positioned at the last character of the string. Move those indeces inwards towards the center.
```cpp
bool isPalindrome(string str) {
	int leftIdx = 0;
	int rightIdx = str.length() - 1;

	while (leftIdx < rightIdx) {
	...
	leftIdx++;
	rightIdx--;
	}
```

Compare characters of both indices; if they are not the same, keep adjusting index position; otherwise, the string is aplindrome.
```cpp
		...
		if (str[leftIdx] != str[rightIdx]) {
			return false;
		}
		...

	return true;
}
```

In the main function, create an empty string to hold the longest subtring, then loop through the input string twice. Then create a substring from the input string, which starts at the position of the outer loop's index, and ends at the inner loop's index.
```cpp
string longest = "";

for (int i = 0; i < str.length(); i++) {
	for (int j = 0; j < str.length(); j++) {
		string subString = str.substr(i, j + 1 - i);
		...
	}
}

return longest;
```

To check of the current substring is a palindrome, use the helper function created earlier and pass it the current substring as a parameter. Also, check if the current substring's length is bigger the longest string's length; if so, update the longest string to be the current substring.
```cpp
		...
		if (isPalindrome(subString) && subString.length() > longest.length()) {
			longest = subString;
		}
		...
```

### Complexity Analysis
O(n^3) Time | O(n) Space
