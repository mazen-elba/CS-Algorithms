### Monotonic Array
> Write a function that takes an array of integers and returns a boolean representing whether the array is monotonic.<br/>
> An array is monotonic if its elements (from left to right) are entirely non-increasing or entirely non-decreasing.<br/>
> Note: empty arrays and arrays of one element are monotonic.

### Input
array = [-1, -5, -10, -1100, -1100, -1101, -1102, -9001]

### Output
true

### Solution
Initiate boolean variables for increasing and decreasing statuses.
```cpp
bool isIncreasing = true;
bool isDecreasing = true;
...
```

Assume that the array is both entirely non-decreasing and entirely non-increasing. As you iterate through each element, perform a check to see if you can invalidate one or both of your assumptions.
```cpp
...
for (int i = 1; i < array.size(); i++) {
	if (array[i] < array[i-1]) {
		isIncreasing = false;
	}

	if (array[i] > array[i-1]) {
		isDecreasing = false;
	}
}

return isIncreasing || isDecreasing;
```

### Complexity Analysis
O(n) Time | O(1) Space
