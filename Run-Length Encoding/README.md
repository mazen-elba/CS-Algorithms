### Run-Length Encoding
> Write a function that takes in a non-empty string and returns its run-length encoding.<br/>
>  Run-Length Encoding - a form of lossless data compression in which runs of data are stored as a single data value and count (rather than as the original run).<br/>
> Note: the input string can contain all sorts of special characters, including numbers.<br/>
> Cannot naively run-length-encode long runs. Thus, long runs (runs of 10 or more characters) should be encoded in a split fashion.

### Input 
string = "AAAAAAAAAAAAABBCCCCDD"

### Output
"9A4A2B4C2D"

### Solution
Start with initiating a current-run counter and and empty string for encoded characters you find.
```cpp
vector<char> encodedChars;
int currentRunLength = 1;
...
```

Traverse the input string and counter the length of each run.
```cpp
for (int i = 1; i < str.size(); i++) {
	char currentChar = str[i];
	char prevChar = str[i - 1];
	...
```

Compare if the current character matches the previously run character, or when you reach a run length of 9 or the end of a run, store the computed count for the run as well as its character, and reset the count to 1 before continuing to traverse the string.
```cpp
	...
	if (currentChar != prevChar || currentRunLength == 9) {
		encodedChars.push_back(to_string(currentRunLength)[0]);
		encodedChars.push_back(prevChar);
		currentRunLength = 0;
	}

	currentRunLength++;
	...
```

Handle the last run.
```cpp
...
encodedChars.push_back(to_string(currentRunLength)[0]);
encodedChars.push_back(str[str.size() - 1]);
...
```

Attach all the characters together and return the finished string.
```cpp
...
string encodedString(encodedChars.begin(), encoded.chars.end());

return encodedString;
```

### Complexity Analysis
O(n) Time | O(n) Space
