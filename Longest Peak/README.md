### Longest Peak
> Write a function that takes in an array of integers and returns the length of the longest peak in the array.<br/>
> A Peak is defined as adjacent integers in the array that are **strictly increasing** until they reach a tip (the highest value in the peak), at which point they become **strictly decreasing**. At least three integers are required to form a peak.

### Input
array = [1, 2, 3, 3, 4, 0, 10, 6, 5, -1, -3, 2, 3]

### Output
6   // 0, 10, 6, 5, -1, -3

### Solution
Initiate a maximum peak length counter and a starting index pointer at the second element of the array. Iterate through the array from left to right, and treat every integer as the potential tip of a peak. To be the tip of peak, an integer has to be strictly greater than its adjacent integers.
```cpp
int maxPeakLength = 0;
int i = 1;

while (i < int(array.size() - 1)) {
	...
	int leftIdx = i - 2;
	while (leftIdx >= 0 && array[leftIdx] < array[leftIdx + 1]) {
		leftIdx--;
	}

	int rightIdx = i + 1;
	while (rightIdx < array.size() && array[rightIdx] < array[rightIdx - 1]) {
		rightIdx++;
	}
	...
}
```

Whenever you find a tip of a peak, expand outwards from the tip until you no longer have a peak. Keep track of the longest peak you find as you iterate through the array.
```cpp
...
int currentPeakLength = rightIdx - leftIdx - 1;
maxPeakLength = max(maxPeakLength, currentPeakLength);
i = rightIdx;
```

### Complexity Analysis
O(n) Time | O(1) Space
