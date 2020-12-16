Two Number Sum

Write a function that takes in a non-empty array of distinct integers and an integer representing a target sum. If any two numbers in the input array sum up to the target sum, the function should return them in an array, in any order. If no two numbers sum up to the target sum, the function should return an empty array.

INPUT
array = [3, 5, -4, 8, 11, -1, 6]
targetSum = 10

OUTPUT
[-1, 11]

```cpp
    for (int i = 0; i < array.size(); i++) {
        ```
        ```cpp
        for (int j = i + 1; array.size(); j++) {
            ```
            ```cpp
            if (targetSum == array[i] + array[j]) {
                ```
                ```cpp
                return vector<int>{array[i], array[j]};
                ```
            }
        }
    }
    return {};
```