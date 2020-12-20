### Validate Subsequence
> Given two non-empty array of integers, write a function that determines whether the second array if a subsequence of the first one.<br/>

> A subsequence of the an array of an array is a set of numbers that aren't necessarily adjacent in the array, but that are in the same order as they appear in the array.

### Input
array = [5, 1, 22, 25, 6, -1, 8, 10]<br/>
sequence = [1, 6, -1, 10]

### Output
true

### Solution
Declare a variable holding your position in the potential sequence. At first, this position will be the 0th index in the sequence; as you find the sequence's integers in the main array, you'll increment the position varibales until you reach the end of the sequence.
```cpp
int arrIdx = 0;
int seqIdx = 0;
```
Iterate through the main input array once, and look for the first integer in the potential subsequence.
```cpp
    while (arrIdx < array.size() && seqIdx < sequence.size()) {
        ...
    }
```
If you find that integer, keep on iterating through the main array, but now look for the second integer in the potential subsequence.<br/>

Continue this process until you either find every integer in the potential subsequence or you reach the end of the main array.
```cpp
    ...
    if (array[arrIdx] == sequence[seqIdx]){
        seqIdx++;
    }
    arrIdx++;
    ...
```
Return *true* if the number if elements in the subsequence matches the number of positions counted.
```cpp
    return seqIdx == sequence.size();
```
### Optimal Complexity 
O(n) Time | O(1) Space

### Data Structure - Array (C/C++)
* An array is a series of elements of the same type (placed in continguous memory locations) 

* Can be individually referenced (by adding an index to a unique identifier)

* Conatiner Properties
    * *Sequence*: elements in sequence containers are ordered in a strict linear sequence (individual elements are accessed by their position in this sequence)
    * *Contiguous Storage*: elements are stored in contiguous memory locations (allowing constant time random access to elements). Pointers to an element can be offset to access other elements
    * *Fixed-Size Aggregate*: container uses implicit constructors and destructors to allocate required space statically (its size is compile-time constant; no memory or time overhead)

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