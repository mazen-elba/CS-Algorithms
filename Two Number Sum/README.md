### Two Number Sum
> Write a function that takes in a non-empty array of distinct integers and an integer representing a target sum. If any two numbers in the input array sum up to the target sum, the function should return them in an array, in any order. If no two numbers sum up to the target sum, the function should return an empty array.

### Input
array = [3, 5, -4, 8, 11, -1, 6]<br/>
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
* An array is a series of elements of the same type (placed in continguous memory locations) 

* Can be individually referenced (by adding an index to a unique identifier)

* In C++, arrays are blocks of static memory whose size must be determined at compile time (before program runs)

* In C++, an array must be declared beffore it is used
> __type name [elements];__
```cpp
int foo [5];
```

* By default, regular arrays of _local scope_ are left uninitialized (none of its elements are set to any particular value; their content are undetermined at the point the array is declared)

* Elements in an array can be explicitly initialized to specific values when declared (by enclosing those initial values in braces {})
```cpp
int foo [5] = {16, 2, 77, 40, 5213};
```

* Number of values between braces {} shall not be greater than number of elements in the array
```cpp
int bar [5] = {10, 20, 30};
```

* Initializer can even have no values, just braces
```cpp
int baz [5] = {};
```

* Optionally, via _universal initialization_, there is no longer need for the equal size between the declaration and the initializer (both these statement are equivalent)
```cpp
int foo[] = {10, 20, 30};
int foo[] {12, 20, 30};
```

* Valued of any of the elements in an array can be accessed just like the value of a regular variable of the same type
> __name [index]__
```cpp
foo [2] = 75; // access 3rd element of the array
x = foo[2];   // x = 75
```