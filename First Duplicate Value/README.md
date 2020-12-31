### First Duplicate Value
> Given an array of integers, write a function that returns the first integer that appears more than once (when the array is read from left to right). <br/>
> In other words, out of all the integers that might occur more than once in the input array, the function should return the one whose first duplicate value has the minimum index.<br/>
> If no integer appears more than once, the function should return -1.<br/>
> Note: you are allowed to mutate the input array.

### Input
array = [2, 1, 5, 2, 3, 3, 4]

### Output
2

### Solution
Initiate a minimum index position for the second (duplicate) integer to equal the input array size. Then use two loops to compare elements from the outer loop with each element after it in the inner loop.
```cpp
int minSecondIdx = array.size();

for (int i = 0; i < array.size(); i++) {
	for (int j = i + 1; j < array.size(); j++) { 
		...
	}
}
```

If you find duplicate integers, update the minimum index position for the second (duplicate) integer to equal the smallest of the current minimum and the inner loop's element position.
```cpp	
		...
		if (array[i] == array[j]) {
			minSecondIdx = min(minSecondIdx, j);	
		}
		...
```

If there are no duplicate elements, return -1. Otherwise, return the element at the minimum index position of the duplicate.
```cpp
	if (minSecondIdx == array.size()) {
		return -1;
	}

	return array[minSecondIdx];
```

### Complexity Analysis
O(n^2) Time | O(1) Space
