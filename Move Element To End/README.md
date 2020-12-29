### Move Element To End
> Given an array of integers and an integer, write a function that moves all instances of that integers in the array to the end of the array and returns the array.<br/>
> The function should perform this in place (ie; it should mutate input array) and doesn't need to maintain the order of the integers.

### Input
array = [2, 1, 2, 2, 2, 3, 4, 2]<br/>
toMove = 2

### Output
[1, 3, 4, 2, 2, 2, 2, 2] // numbers 1, 3, and 4 could be ordered differently

### Solution
Set two pointers at the start and end of the array, respectively, and progressively moving them inwards.
```cpp
int i = 0;
int j = array.size() - 1;
...
```

Move the right pointer inwards (so long as it points to the itneger to move), and move the left pointer inwards (so long as it doesn't point to the integer to move).
```cpp
...
while (i < j) {
	while (i < j && array[j] == toMove) {
		j--;
	}
	...
}
```

If you find the given integer to match the current element, swap their positions.
```cpp
	...
	if (array[i] == toMove) {
		swap(array[i], array[j]);
	}
	i++;
	...
```

### Complexity Analysis
O(n) Time | O(1) Space
