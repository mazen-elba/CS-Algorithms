### Four Number Sum
> Write a function that takes in a non-empty array of distinct integers and an integer represeting a target sum. The function should find all quadruplets in the array that sum up to the target sum and return a 2D array (matrix) of all these quadruplets in no particular order.<br/>
> If no four numbers sum up to the target sum, the function should return an empty array.

### Input
array = [7, 6, 4, -1, 1, 2]

### Output
[[7, 6, 4, -1], [7, 6, 1, 2]] // quadruplets could be ordered differently

### Solution
To store all of these sums, create a hash table mapping the sume of every pair of numbers in the array to an array of arrays, with each subarray representing the indices of each pair summing up to that number (numbers summing up to these two sums constitute candidates for valid quadruplets; make sure that no number was used to generate both of the two sums). Then calculate the sums of every pair of numbers in the array using two sibling for-loops nested inside a third for-loop.
```cpp
unordered_map<int, vector<vector<int>>> pairSums;
vector<vector<int>> quadruplets;
...
```

First, loop through the input array with a simple for-loop. Inside this loop, loop through the input array again, starting at the index of the first loop. At each iteration, calculate the difference between the target sum and the sum of the two numbers represented by the indices of the for-loops.
```cpp
...
for (int i = 1; i < array.size() - 1; i++) {
	for (int j = i + 1; j < array.size(); j++) {
		int currentSum = array[i] + array[j];
		int sumDiff = targetSum - currentSum;
		...
```

If that difference is in the hash table you're building, then calid quadruplets can be formed by combining the current pair of numbers iwth each pair stored in the hash table at the difference just calculated.
```cpp
		...
		if (pairSums.find(sumDiff) != pairSums.end()) {
			for (vector<int> pair: pairSums[sumDiff]) {
				pair.push_back(array[i]);
				pair.push_back(array[j]);
				quadruplets.push_back(pair;
			}
		}
	}
	...
}

return quadruplets;
```

Following the first nested for-loop, loop through the array again, this time starting at the index zero all the way to the index for the first for-loop. At each iteration, calculate the sum of the two numbers represented by the indices of the for-loops and add iot to the hash table (if isn't already there); then add the pair of indices to the array that sum in the hash table maps to.
```cpp
	...
	for (int k = 0; k < i; k++) {	
		int currentSum = array[i] + array[k];

		if (pairSums.find(currentSum) == pairSums.end()) {
			pairSums[currentSum] = vector<vector<int>>{{array[k], array[i]}};
		} else {
			pairSums[currentSum].push_back(vector<int>{array[k], array[i]});
		}
	}
	...
```

### Complexity Analysis 
Average: O(n^2) Time | O(n^2) Space<br/>
Worst: O(n^3) Time | O(n^2) Space
