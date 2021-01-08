### Valid IP Address
> Given a string of length 12 or smaller, containing only digits, write a function that returns all the possible IP addresses that can be created by inserting three "."s in the string.<br>
> An IP address is a sequence of four positive integers that are separated by "."s, where each individual integer is within the range of 0 - 255, inclusive.<br/>
> An IP address is not valid if any of the individual integers contains leading 0s.<br/>
> The function should return the IP addresses in string format and in no particular order. If no valid IP addresses can be created from the string, the function should return an empty list.

### Input
string = "1921680"

### Output
[<br/>
  "1.9.216.80",<br/>
  "1.92.16.80",<br/>
  "1.92..168.0",<br/>
  "19.2.16.80",<br/>
  "19.2.168.0",<br/>
  "19.21.6.80",<br/>
  "19.21.68.0",<br/>
  "19.216.8.0",<br/>
  "192.1.6.80",<br/>
  "192.1.68.0",<br/>
  "192.16.8.0"<br/>
]

### Solution
Split the problem into sub-problems:<br/>
Main Part - Go Through All Combinations of Valid IP-Address Parts<br/>
Create substrings of the main input string that starts at the first character and that have lengths 1, 2, and 3. 
```cpp
vector<string> validIPAddresses(string str) {
	vector<string> ipAddressesFound;

	for (int i = 1; i < min((int)str.length(), 4); i++) {
		vector<string> currentIPParts = {"", "", "", ""};
		currentIPParts[0] = str.substr(0, i);

		if (!isValidPart(currentIPParts[0])) {
			continue;
		}
		...
```

Repeat the above process for the second part, where the substrings will start where the first part ended.
```cpp
		...
		for (int j = i + 1; j < i + min((int)str.length() - i, 4); j++) {
			currentIPParts[1] = str.substr(i, j - i);

			if (!isValidPart(currentIPParts[1])) {
				continue;
			}
			...
```

Same thing applies for the third and fourth parts. After find all the required parts, add each substring to the final array, then eturn that array of all the valid IP-Addresses.
```cpp
			...
			for (int k = j + 1; k < j + min((int)str.length(0 - j, 4); k++) {
				currentIPParts[2] = str.substr(j, k - j);
				currentIPParts[3] = str.substr(k);

				if (isValidPart(currentIPParts[2]) && isValidPart(currentIPParts[3])) {
					ipAddressessFound.push_back(join(currentIPParts));
				}
			}
		}
	}

	return ipAddressessFound;
}
```

Sub-Part - Find One Valid Part at a Time<br/>
```cpp
bool isValidPart(string str) {
	int strAsInt = stoi(str);

	if (strAsInt > 255) {   // each integer is 0 - 255 (inclusive)
		return false;
	}

	return str.length() == to_string(strAsInt).length();   // check for leading 0s
}
```

Sub-Part - Join All Substrings into One String<br/>
Combine sets of four valid parts to create one valid IP address.
```cpp
string join(vector<string> strings) {
	string str;

	for (int i = 0; i < strings.size(); i++) {
		str += strings[i];
		
		if (i < strings.size() - 1) {
			str += ".";   // added "." at end of each valid integer (of lengths 1, 2, or 3)
		}
	}

	return str;
}
```


### Complexity Analysis
O(1) Time | O(1) Space
