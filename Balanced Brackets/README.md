### Balanced Brackets
> Write a function that takes in a string made up of brackets (```(```, ```[```, ```{```, ```)```, ```]```, ```}```) and other optional characters. The function should return a boolean representing whether the string is balanced with regards to brackets.\\
> A string is said to be balanaced if it has as many opening brackets of a certain type as it has closing brackets of that type and if no bracket is unmatched.\\
> NOTE: an opening bracket cannot match a corresponding closing bracket that comes before it, and similarly, a closing bracket cannot match a corresponding opening bracket that comes afeter it. Also, brackets cannot overlap each other as in ```[(])```.

### Input
```
string = "([])(){}(())()()"
```

### Output
```
true   // string is balanced
```

### Solution
There are two scenarios in which the input string will be unbalanced: either you run into a closing bracket with no prior matching opening bracket, or you get the end of the string with some opening brackets that have not been matched.\\
Therefore, use a hash table auxilary data structure to keep track of all the brackets, and efficiently check if you run into an unbalanced scenario at every iteration.\\

Use a stack data structure to store opening brackets as you traverse the string. The LIFO property of the stack should allow matching of any closing brackets that you run into against the most recent opening bracket, if one exists, in which case you can pop it out of the stack.
```cpp
string openingBrackets = "([{";
string closingBrackets = ")]}";
stack<char> stack;
unordered_map<char, char> matchingBrackets{{")", "("}, {"]", "["}, {"}", "{"}};
...
```

Traverse the characters of the input string.
```cpp
for (char character : str) {
	...
}
```
Check for any brackets in the string. If you find an opening bracket, add it to the top of the stack. If you find a closing bracket, check if the stack is empty or full; if the stack is empty, it's an unbalanced stack.
```cpp
	...
	if (openingBrackets.find(character) != string::npos) {
		stack.push(character);
	} else if (closingBrackets.find(character) != string::npos) {
		if (stack.size() == 0) {
			return false;
		}
		...
	}
```

Check if the current closing bracket at the *top* of the stack matches any of the closing brackets tracked in the hash table; if so, remove the closing bracket at the *top* of the stack; otherwise, it is an unbalanced stack.
```cpp
		...
		if (stack.top() == matchingBrackets[character]) {
			stack.pop();
		} else {
			return false;
		}
		...
```

Finally, check if the stack is balanced (ie; has even number of characters).
```cpp
...
return stack.size() == 0;
```

### Complexity Analysis
O(n) Time | O(n) Space
