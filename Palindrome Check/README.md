### Palindrome Check
> Write a function that takes a non-empty string and returns a boolean representing whether the string is a palindrome.<br/>
> A palindrome is a string that's written the same forward and backward.<br/>
> Note: single-character strings are palindromes.

### Input
string = "rotator"

### Output
true

### Solution
Start with a pointer at the last index of the input string and move backwards. 
```cpp
for (int c = str.size() - 1; c >= 0; c--) {
	...
```

Build the input string in reverse order and compare this newly built string to the input string.
```cpp
	...
	strReversed += str[c];
	...
```

Compare the newly built string to the input string.
```cpp
...
return str == strReversed;
}
```

### Complexity Analysis
O(n^2) Time | O(n) Space
