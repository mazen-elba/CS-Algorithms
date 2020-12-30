### Array of Products
> Write a function that takes in a non-empty array of integers and returns an array of the same length, where each element in the output array is equal to the product of every other number in the input array.<br/>
> For example, the value at *output[i]* is equal to the product of every number in the input array other than *input[i]*.

### Input
array = [5, 1, 4, 2]

### Output
[8, 40, 10, 20]<br/>
// 8 = 1 x 4 x 2<br/>
// 40 = 5 x 4 x 2<br/>
// 10 = 5 x 1 x 2<br/>
// 20 = 5 x 1 x 4

### Solution
Initiate a new output array (with a size to be equal to the input array's size).
```cpp
vector<int> productArray(array.size(), 1);
...
```

Use two loops through the input array: one from the left to the right, and one from the right to the left. For each index in the input array, calculate the product of every element to the left, and the product of every element to the right.
```cpp
...
int leftCurrentProduct = 1;
for (int i = 0; i < array.size(); i++) {
	productArray[i] = leftCurrentProduct;
	leftCurrentProduct *= array[i];
}

int rightCurrentProduct = 1;
for (int i = array.size() - 1; i >= 0; i--) {
	productArray[i] *= rightCurrentProduct;
	rightCurrentProduct *= array[i];
}
...
```

### Complexity Analysis
O(n) Time | O(n) Space
