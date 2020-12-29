### Smallest Difference
> Write a function that takes in two non-empty arrays of integers, finds the pair of numbers (one from each array) whose absolute difference is closest to zero, and returns an array containing these two numbers, with the number from the first array in the first position

### Input
arrayOne = [-1, 5, 10, 20, 28, 3]<br/>
arrayTwo = [26, 134, 135, 15, 17]

### Output
[28, 26]

### Solution
Start by sorting both arrays. Initiate starting pointers and difference counters.
```cpp
sort(arrayOne.begin(), arrayOne.end());
sort(arrayTwo.begin(), arrayTwo.end();

int idxOne = 0;
int idxTwo = 0;
int smallestDiff = INT_MAX;
int currentDiff = INT_MAX;
...
```

Set a pointer at the beginning of both arrays and evaluate the absolute difference of the pointer-numbers.
```cpp
...
while (idxOne < arrayOne.size() && idxTwo < arrayTwo.size()) {
	int firstNum = arrayOne[idxOne];
	int secondNum = arrayTwo[idxTwo];
	...
}
```

If the difference is equal to zero, then you've found the closest pair; otherwise, increment the pointer of the smaller of the two numbers to find a potentially better pair. Continue until you get a pair with a difference of zero or until one of the pointers gets out of range of its array. 
```cpp
...
if (firstNum < secondNum) {
	currentDiff = secondNum - firstNum;
	idxOne++;
} else if (secondNum < firstNum) {
	currentDiff = firstNum - secondNum;
	idxTwo++;
} else {
	return vector<int> {firstNum, secondNum};
}
...
```

If the smallest difference counter is more than the current difference counter, update the smallest difference counter to equal the current difference counter; then return an array of the smallest pair of elements.
```cpp
...
if (smallestDiff > currentDiff) {
	smallestDiff = currentDiff;
	smallestPair = {firstNum, secondNum};
}
...
```

### Complexity Analysis
O(n log(n) + m log(m)) Time | O(1) Space
