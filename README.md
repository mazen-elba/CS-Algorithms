# Arrays (C/C++)

* Container Properties
	* *Sequence*: elements are ordered in a strict linear sequence (individual elements are accessed by their position in the sequence)
	* *Contiguous Storage*: elements are stored in contiguous memory locations (allowing *O(1)* Time random access to elements)
	* *Fixed-Size Aggregate*: uses implicit constructors and destructors to allocate required space statically (size is compile-time constant; no memory or time overhead)

* An array is a series of elements of the same type (placed in continguous memory locations)

* Arrays are blocks of static memory, whose size must be determined at compile time (before program runs)

* Arrays can be individually referenced (by adding an index to a unique identifier)

* An array musy be declared before it is used
> **type name [elements];**
```cpp
int foo [5];
```

* By dafault, regular arrays of *local_scope* are left uninitialized (none of its elements are set to any particular value; their content are undetermined at the point the array is declared)

* Elements are explicitly initialized to specific values when declared (by enclosing those initial values in braces{})
```cpp
int foo [5] = {16, 2, 77, 40, 23452};
```

* Number of values between braces {} shall not be greater than number of elements
```cpp
int bar [5] = {10, 20, 30};
```

* Initializer can have no values (empty braces)
```cpp
int baz [5] = {};
```

* Optionally, via *universal initialization*, there is no need for the equal size between the declaration and the initializer (below statements are equivalent)
```cpp
int foo[] = {10, 20, 30};
int for[] {10, 20, 30};
```

* Values of any of the elements can be accessed just like the value of a regular variable of the same type
> **name [index]**
```cpp
foo [2] = 75; // accesses 3rd element of the array
x = foo[2];   // assigns 75 to x
```

### Strings (C/C++)

* C-style strings are a special case of an array of characters
```cpp
std::cout << "Hello World";
```

* Above string is euivalent to using the array declaration
```cpp
char sayHello[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0'};
```

* The last character in the array is a *null* character *'\0'* (ie; string-termination character, which tells the compiler that the string has ended). The string's last character *always* precedes the null-terminator '\0'. When you embed a string literal, the compiler does the job of adding a '\0' after it.

* If you inserted '\0' anywhere in the middle of the array, it would not change the size of the array; it owuld only mean that string-processing would stop at that point.

* C++ offers a better option for string literals (std::string), which provides convenient utility functions (to determine length, concatenate, etc.)

* C++ standard strings are more efficient and safer to deal with text input, and perform string manipulation

* C++ std::string are dynamic in size (unlike  C-style's char array implementation), and can scale when data needs it

* STL string class is a container (supplied by the standard template library), that helps with string manipulation requirements.

* Advantages of suing string class: 
	* Memory Mangement
	* String Comparison
	* String Manipulation
