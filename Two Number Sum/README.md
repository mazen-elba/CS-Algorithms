### Two Number Sum
> Write a function that takes in a non-empty array of distinct integers and an integer representing a target sum. If any two numbers in the input array sum up to the target sum, the function should return them in an array, in any order. If no two numbers sum up to the target sum, the function should return an empty array.

### Input
array = [3, 5, -4, 8, 11, -1, 6]
targetSum = 10

### Output
[-1, 11]

### Solution
Use two loops to sum all possible pairs of numbers in the input array. For every number X in the input array, find a corresponding number Y such that X + Y = targetSum.
```cpp
    for (int i = 0; i < array.size(); i++) {
        for (int j = i + 1; array.size(); j++) {
            ...
        }
    }
```
If there is a match of elements X and Y (in any order) that add up to the targetSum, add both elements to a new array, and return that array.
```cpp
    if (targetSum == array[i] + array[j]) {
        return vector<int>{array[i], array[j]};
    }
```
If there is no match of elements X and Y that add up to the targetSum, return an empty array.
```cpp
    return {};
```
### Optimal Complexity 
O(n) Time | O(n) Space

### Data Structure - Array