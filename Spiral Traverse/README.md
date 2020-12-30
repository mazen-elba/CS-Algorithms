### Spiral Traverse
> Write a function that takes in an N x M two-dimensional array (squared or not squared) and returns a one-dimensional array of all the array's elements in spiral order.<br/>
> Spiral order starts at the top left corner of the two-dimensional array, goes to the right, and proceeds in a spiral pattern all the way until every element has been visited.

### Input
array = [<br/>
[1, 2, 3, 4],<br/>
[12, 13, 14, 5],<br/>
[11, 16, 15, 6],<br/>
[10, 9, 8, 7],<br/>
   	]<br/>

### Output
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]

### Solution
Declare four variables: a starting row, a starting column, an ending row, and ending column. These variables represent the bounds of the first rectangle perimeter in the spiral that you have to traverse.
```cpp
...
int startRow = 0;
int endRow = array.size() - 1;
int startCol = 0;
int endCol = array[0].size() - 1;
...
```

Traverse the rectangle perimeter using those variable bounds, and then move the bounds inwards. End the algorithm once the starting row passes the ending row or the starting column passes the ending column.
```cpp
...
while (startRow <= endRow && startCol <= endCol) {
	for (int col = startCol; col <= endCol; col++) {
		result.push_back(array[startRow][col]);
	}

	for (int row = startRow + 1; row <= endRow; row++) {
		result.push_back(array[row][endCol]);
	}
	...
```

Handle the edge case where there is a single row or a single column in the middle of the matrix. In this case, we don't want to double-count the values in this row or column.
```cpp
	...
	for (int col = endCol - 1; col >= startCol; col--) {
		if (startRow == endRow) {
			break;
		}
		result.push_back(array[endRow][col]);
	}
 
	for (int row = endRow - 1; row > startRow; row--) {
		if (startCol == endCol) {
			break;
		}	
		result.push_back(array[row][startCol]);
	}

	startRow++;
	endRow--;
	startCol++;
	endCol--;
	}

return result;
```

### Complexity Analysis
O(n) Time | O(n) Space
