### Group Anagrams
> Given an array of strings, write a function that groups anagrams together, and returns a list of anagram groups in no particular order.<br/>
> Anagrams - strings made up of exactly the same letters, where order doesn't matter.<br/>

### Input
words = ["yo", "act", "flop", "tac", "foo", "cat", "oy", "olfp"]

### Output
[["yo", "oy"], ["flop", "olfp"], ["act", "tac", "cat"], ["foo"]]

### Solution
Create a hash table to store each unqiue string as a key, and each grouping of anagrams as their values.
```cpp
unordered_map<string, vector<string>> anagrams;
```

Traverse the input list of strings, then rearrange every input string such that each string's letters are ordered in alphabetical order (ie; sort each word).
```cpp
for (string word : words) {
	string sortedWord = word;
	sort(sortedWord.begin(), sortedWord.end());
	...
}
```

Store the resulting string in a hash table. For any two of the resulting strings that are equal to each other, their original strings (with their letters in normal order) must be anagrams. Therefore, group all of these resulting strings together, all while keeping track of their original strings.
```cpp
	...
	if (anagrams.find(sortedWord) != anagrams.end()) {
		anagrams[sortedWord].push_back(word);
	} else {
		anagrams[sortedWord] = vector<string>{word};
	}
	...
```

Traverse each list of strings in the created hash table, then find the groups of anagrams.
```cpp
...
vector<vector<string>> groupAnagrams;

for (auto list : anagrams) {
	groupAnagrams.push_back(list.second);
}

return groupAnagrams;
```

### Complexity Analysis
O(w * n * log(n)) Time | O(w * n) Space
