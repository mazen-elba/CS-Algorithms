### Min Max Stack Construction
> Write a class for a Min Max Stack. The class should support:<br/>
> - Pushing-on and Popping-off values<br/>
> - Peeking-at the value the top of the stack<br/>
> - Getting both the minimum and the maximum values in at any given point in time<br/>
> All class methods, when considered independently, should run in constant time and constant space

### Input: Output
MinMaxStack(): - // instantiate Stack class<br/>
push(5): -       // [5]<br/>
getMin(): 5      //  .<br/>
getMax(): 5      //  .<br/>
peek(): 5        //  .<br/>
push(7): -       // [7,5]<br/>
getMin(): 5      //  .<br/>
getMax(): 7      //  .<br/>
peek(): 7        //  .<br/>
push(2): -       // [2,7,5]<br/>
getMin(): 2      //  .<br/>
getMax(): 7      //  .<br/>
peek(): 2        //  .<br/>
pop(): 2         // [7,5]<br/>
pop(): 7         // [5]<br/>
getMin(): 5      //  .<br/>
getMax(): 5      //  .<br/>
peek(): 5        //  .<br/>

### Solution
Initiate an *array* container to keep track of minimum and maximum value, in order to be able to push values on, pop values off, and peek at values on top of the stack at any time and in *constant* time, using *constant* space.<br/>
Initiate a *hash table* data structure to get the minimum and maximum values in the stack at any time and in *constant* time, suing *constant* space.<br/>
NOTE: *top* of stack = *last* element inserted
```cpp
// Implementation Using an Array
class MinMaxStack {
public:
	vector<unordered_map<string, int>> minMaxStack = {}; // create an empty array of a hash table
	vector<int> stack = {}; // creat an empty array
	...
};
```

Get the value of the *top* element without removing it.
```cpp
	...
	int peek() {
		return stack[stack.size() - 1]; // access the *last* element inserted
	}
	...
```

Remove an element from the *top* of the stack.
```cpp
	...
	int pop() {
		minMaxStack.pop_back();
		int result = stack[stack.size() - 1]; // access the *last* element inserted, 
		stack.pop_back();

		return result;
	}
	...
```

Add an element to the *top* of the stack. Since the minimum and maximum values can change, keep track of all the min(s) and max(s) at every value in the stack.
```cpp
	...
	void push(int number) {
		// store the new min and max values
		unordered_map<string, int> newMinMax = {{"min", number}, {"max", number}};

		// check if the stack is not empty
		if (minMaxStack.size()) {
			unordered_map<string, int> lastMinMax = minMaxStack[minMaxStack.size() - 1]; // access the *last* values of min and max

			// compare current min/max values with new min/max values
			// ... update hash table's min/max values according to comparisons
			newMinMax["min"] = min(lastMinMax["min"], number);
			newMinMax["max"] = max(lastMinMax["max"], number);
		}

		minMaxStack.push_back(newMinMax); // append the new min/max values to the stack
		stack.push_back(number); // append the new number to the *top* of the stack
	}
	...
```

Get the current minimum and maximum values of the stack.
```cpp
	...
	int getMin() {
		return minMaxStack[minMaxStack.size() - 1]["min"];
	}

	int getMax() {
		return minMaxStack[minMaxStack.size() - 1]["max"];
	}
	...
```

### Complexty Analysisi
O(1) Time | O(1) Space - for each independent method
