# Arrays (C++)

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

# Strings (C++)

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

# Stacks (C++)

* Basic Operations (LIFO or FILO)
	* **Push** - add an element to the top of a stack
	* **Pop** - remove an element from the top of a stack
	* **Peek/Top** - get the value of the top element without removing it
	* **isEmpty** - check if the stack is empty; if so, it is an *underflow* condition
	* **isFull** - check if the stack is full; if so, it is an *overflow* condition

* Implementation (insertion/deletion happen on *same* end):
	* Using array
		* Pros: easy to implement; saves memory (pointers are not involved)
		* Cons: not dynamic (doesn't grow/shrink depending on needs at runtime)
	* Using linked list
		* Pros: dynamic (grows/shrinks according to needs at runtime)
		* Cons: requires extra memory (due to pointers)

* How a Stack Works:
	* A pointer called TOP is used to keep track of the top element in the stack
	* When initializing the stack, we set its value to -1 so that we can check if the stack is empty (by comparing TOP == -1)
	* On pushing an element, we increase the calue of TOP and place the new element in the position pointed to by TOP
		* Before pushing, check if the stack is already full
	* On popping an element, we return the element pointed to by TOP and reduce its value
		* Before popping, check if the stack is already empty

* Complexity Analysis
	* For array-based implementation of a stack, **push** and **pop** operations take constant time (ie; O(1))

* Common Applications 
	* To reverse a word - put all the letters in a stack and pop them out
	* In compilers - to calculate the calue of expressions by converting the expression to prefix/postfix form
	* In browsers - each time a page is visited, it is added on top of a stack; pressing the back button, the current URL is removed from the stack, and the previous URL is accessed

* Implementation (using an Array)
```cpp
#define MAX 10

int size = 0;

// CREATE A STACK
struct stack {
	int items[MAX];
	int top;
};

typedef struct stack st;

void createEmptyStack(st *s) {
	s->top = -1;
}

// CHECK IF STACK IS FULL
int isFull(st *s) {
	if (s->top == MAX - 1) {
		return 1;
	} else {
		return 0;
	}
}

// CHECK IF STACK IS EMPTY
int isEmpty(st *s) {
	if (s->top == -1) {
		return 1;
	} else {
		return 0;
	}
}

// ADD ELEMENTS INTO STACK
void push(st *s, int newItem) {
	if (isFull(s)) {
		cout << "STACK FULL";   // it is an overflow condition
	} else {
		s->top++;
		s->items[s->top] = newItem;
	}
	size++;
}

// REMOVE AN ELEMENT FROM STACK
void pop(st *s) {
	if (isEmpty(s)) {
		cout << "STACK EMPTY";   // it is underflow condition
	} else {
		s->items[s->top]);   // item popped
		s->top--;
	}
	size--;
}

// PRINT ELEMENTS OF STACK
void displayElements(st *s) {
	for (int i = 0; i , size; i++) {
		cout << s->items[i] << " ";
	}
}
```

# Queues

* Four Types of Queues
	* Simple Queue (ie; Queue)
		* Strictly FIFO rules
		* Insertion takes place at the rear
		* Deletion takes place at the front 
	* Circular Queue
		* The last element points to the first element (making a circular link)
		* Can insert an element in the first position
			* If the last position is full, and the first position is empty
		* Advantage over Simple Queue: better memory utilization
	* Priority QUeue (ie; Heap)
		* Each element is associated with a priority, and is served according to its priority
		* If elements with the same priority occur, they are served according to their order in the queue
		* Insertion takes place based on the arrival of the values
		* Deletion takes place based on priority
	* Double-Ended Queue (ie; Deque)
		* Does not follow FIFO rules
		* Insertion and Deletion of elements take place fro meither the front or the rear

* Basic Operations (FIFO):
	* **Enqueue** - add an element to the end of a queue
	* **Dequeue** - remove an element from the front of a queue
	* **isEmpty** - check if the queue is empty; is so, it is an *underflow* condition
	* **isFull** - check if the queue is full; if so, it is an *overflow* condition
	* **Peek/Top** - get the value of the front of a queue without removing it

* Implementation (insertion/deletion happen on *different* ends)
	* Keep track of two indices: rear and front
	* Increment rear and front in *circular* motion
	* Items are *enqueued* at the rear
	* Items are *dequeued* from the front

* How a Queue Works:
	* Two pointers FRONT and REAR
		* FRONT tracks the first element of the queue
		* REAR tracks the last element of the queue
		* Initially, set the values of FRONT and REAR to -1
	* **Enqueue**
		* Check if the queue is full; if so, it is an *overflow* condition
		* For the first element, set the value of FRONT to 0
		* Increase the REAR index by 1
		* Add the new element in the poisition pointed to by REAR
	* **Dequeue**
		* Check if the queue is empty; if so, it is an *underflow* condition
		* Return the value pointed by FRONT
		* Increase the FRONT index by 1
		* For the last element, reset the values of FRONT and REAR to -1

* Complexity Analysis
	* **Enqueue** and **Dequeue** operations take constant time (ie; O(1))

* Common Applications
	* Scheduling - CPU and Disk
	* Synchronization -data transferred asynchronously between two processes (eg; IO buffers, pipes, file IO)
	* Handling of iterruprs in real-time systems
	* Call Center phone systems

* Implementation
```cpp
#define SIZE 5

class Queue {
private: 
	int items[SIZE], front, rear;

public
	Queue() {
		front = -1;
		rear = -1;
	}

	bool isFull() {
		if (front == 0 && rear == SIZE - 1) {
			return true;
		} else {
			return false;
		}
	}

	bool isEmpty() {
		if (front == -1) {
			return true;
		} else {
			return false;
		}
	}

	void enQueue(int element) {
		if (isFull()) {
			cout << "QUEUE FULL";   // overflow condition
		} else {
			if (front == -1) {
				front = 0;
			}
			rear++;

			items[rear] = element;  // element inserted in rear
		}
	}

	int deQueue() {
		int element;

		if (isEmpty()) {
			cout << "QUEUE EMPTY";  // underflow condition
			return -1;
		} else {	
			element = items[front];

			if (front >= rear) {
				front = -1;
				rear = -1;
			} else {   // queue has only one element, so reset queue after deleting element
				front++;
			}

			return element;
		}
	}

	void displayElements() {
		if (isEmpty()) {
			cout << "QUEUE EMPTY";  // underflow condition
		} else {
			cout << "Front Index-> " << front << endl;

			for (int i = front; i <= rear; i++) {
				cout << "item-> " << items[i] << " ";
			}

			cout << "Rear Index-> " << rear << endl;
		}
	}
};
```

### Circular Queues
* How to it Works (additional to Simple Queue)
	* If there is a full queue
		* Case 1: FRONT = 0 and REAR == SIZE - 1
		* Case 2: FRONT = REAR + 1 (this happens when REAR starts from 0; due to circular increment, and when value is 1 less than FRONT)

* Complexity Analysis
	* **Enqueue** and **Dequeue** operations take constant time (ie; O(1)) for an array implementation

* Common Applications
	* CPU scheduling
	* Memory management
	* Traffic management

* Implementation
```cpp
#define SIZE 5

class Queue {
private:
	int items[SIZE], front, rear;

public:
	Queue() {
		front = -1;
		rear = -1;
	}

	// CHECK if QUEUE IS FULL
	bool isFull() {
		if (front == 0 && rear == SIZE - 1) {
			return true;
		}

		if (front == rear + 1) {
			return true;
		}

		return false;
	}

	// CHECK IF QUEUE IS EMPTY
	bool isEmpty() {
		if (front == -1) {
			return truel
		} else { 
			return false;
		}
	}

	// ADDING AN ELEMENT
	void enQueue(int element) {
		if (isFul()) {
			cout << "QUEUE FULL";   // it is an overflow condition
		} else {
			if (front == -1) {
				front = 0;
			}

			rear = (rear + 1) % SIZE;
			items[rear] = element;
		}
	}

	// REMOVING AN ELEMENT
	int deQueue() {
		int element;

		if (isEmpty()) {
			cout << "QUEUE EMPTY";  // is it an underflow condition
			return -1;
		} else {
			element = items[front];
			
			if (front == rear) {
				front = -1;
				rear = -1;
			} else {   // queue has only one element; reset queue after deleting element
				front = (front + 1) % SIZE;
			}
			return element;
		}
	}

	void displayElements() {
		if (isEmpty()) {
			cout << "QUEUE EMPTY" << endl;
		} else {
			cout << "Front Index-> " << front << endl;

			for (int i = front; i != rear; i = (i + 1) % SIZE) {
				cout << "Items-> " << items[i] << endl;
			}

			cout << "Rear Index-> " << rear << endl;
		}
	}
};
```

### Priority Queues (ie; Heaps)

* A priority queue is a queue that does not have the FIFO logic (jumps the line)
	* Can add successive pieces of data and retrieve the one with "highest priority" in O(1) Time

* To implement a priority queue, need a comparison between its elements (to determine priority)

* Properties:
	* Every item has a priority associated with it
	* An element with high priority is *dequeued* before an element with low priority
	* If two element have the *same* priority, they are served according to their order in queue
	* An element with maximum ASCII value will have highest priority

* Basic Operations:
	* **Insert** - add an element with given priority (max-heap)
		1. Insert the new element at the end of the tree
		2. Heapify the tree
	* **Peek** - get the highest priority element from max-heap, or lowest priority element from min-heap
	* **Remove** - remove the highest priority element (max-heap)
		1. Select the element to be deleted
		2. Swap it with the last element
		3. Remove the last element
		4. Heapify the tree

* Implementation (using an array, a linked list, a heap data structure (most efficient), or a BST)
	* Pros: unlike a regular queue, nodes are given weight, which allows them to move towards the head of the queue (rather than being on the tail)
	* Cons: unlike a regular queue, insertion doesn't take a constant time (due to applying insertion sort, and priority)
	* Using an array
	* Using a linked list
	* Using a heap (preferred) 
		* Heaps are an implementation of priority queues

* Complexity Analysis
	* Linked List: peak takes O(1), insert takes O(n), delete takes O(1)
	* Binary Heap: peak takes O(1), insert takes O(log n), delete takes O(log n)
	* BST: peak takes O(1), insert takes O(log n), delete takes O(log n)

* Common Applications
	* Dijkstra's algoritm
	* Implementing a stack
	* Load balancing and interrupt handling in an OS
	* Data compression in Huffman code

* Implementation
```cpp
// SWAP POSITION OF ELEMENTS (helper function)
void swap(int *a, int *b) {
	int temp = a*;
	a* = b*;
	b* = temp;
}

// HEAPIFY A TREE
void heapify(vector<int> &hT, int i) {
	int size = hT.size();

	// FIND THE LARGEST AMONG ROOT, LEFT and RIGHT CHILDREN NODES
	int largest = i;
	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 2;

	if (leftChild < size && hT[leftChild] > ht[largest]) {
		largest = leftChild;
	}

	if (rightChild < size && hT[rightChild] > ht[largest]) {
		largest = rightChild;
	}

	// SWAP and CONTINUE HEAPIFYING IF ROOT IS NOT LARGEST
	if (largest != i) {
		swap(&hT[i], &hT[largest]);
		heapify(hT, largest);
	}
}

// ADD AN ELEMENT INTO A TREE
void insert(vector<int> &hT, int newNum) {
	int size = hT.size();

	if (size == 0) {    // if there is no node, create a node
		hT.push_back(newNum);
	} else {    // if a node already exists, insert the new node at the end (last node from left to right)
		hT.push_back(newNum);

		for (int i = size / 2 - 1; i >= 0; i--) {
			heapify(hT, i);   // heapify the array
		}
	}
}

// REMOVE AN ELEMENT FROM A TREE
void deleteNode(vector<int> &hT, int num) {
	int size = hT.size();
	
	for (int i = 0; i < size; i++) {
		if (num == hT[i]) {    // if node-to-be-deleted is a leaf node, then remove the node
			break;
		}
	}

	swap(&hT[i], &hT[size - 1]);    // swap node-to-be-deleted with the last leaf node, then remove note-to-be-deleted
	hT.pop_back();

	for (int i = size / 2 - 1; i >= 0; i--) {
		heapify(hT, i);    // heapify the array
	}
}

// PRINT THE TREE
void displayElements(vector<int> &hT) {
	for (int i = 0; i < hT.size(); ++i) {
		cout << hT[i] << " " << endl;
	}
}
```

### Double-Ended Queues (Deques);

* Types of Deque
	* Input Restricted
		* Restriction at a single end
		* Deletion at both ends
	* Output Restricted
		* Restriction at a single end
		* Insertion at both ends

* Basic Operations
	* **Insert**
		* At FRONT
			1. Check the position of front; if FRONT < 1, reinitialize FRONT = N - 1
			2 Else, decrease FRONT by 1
			3. Add the new key into ARRAY[FRONT]
		* At REAR
			1. Check if array is full; if so, reinitialize REAR = 0
			2. Else, increase REAR by 1
			3. Add the new key into ARRAY[REAR]
	* **Delete**
		* From FRONT
			1. Check if deque is empty (FRONT = -1); if so, it is an underflow condition
			2. Check if deque has only one element (FRONT = REAR); if so, set FRONT = -1 and REAR = -1
			3. Otherwise, check if FRONT is at the end (FRONT = N - 1);, if so, set go to the front FRONT = 0
			4. Else, FRONT = FRONT + 1
		* From REAR
			1. Check if deque is empty (FRONT = -1); if so, it is an underflow condition
			2. Check if deque has only one element (FRONT = REAR); if so, set FRONT = -1 and REAR = -1
			3. Otherwise, check if REAR is at the fron (REAR = 0); if so, set go to the front REAR = N - 1
			4. Else, REAR = REAR - 1
	* **isEmpty** - check if FRONT = -1
	* **isFull** - check if FRONT = 0 and REAR = n - 1, or FRONT = REAR + 1

* Complexity Analysis
	* All operations take constant time (ie; O(1))

* Common Applications
	* Undo operations on software
	* Store history in browsers
	* Implementing stacks and queues

* Implementation
```cpp
#define MAX 10

class Deque {
	int array[MAX];
	int front;
	int rear;
	int size;

public:
	Deque(int size) {
		front = -1;
		rear = 0;
		this->size = size;
	}

	void inserFront(int key) {
		if (isFull()) {
			cout << "OVERFLOW\N";
			return;
		}

		if (front == -1) {
			front = 0;
			rear = 0;
		} else if (front == 0) {
			front = size - 1;
		} else { 
			front--;
		}

		array[front] = key;
	}

	void insertRear(int key) {
		if (isFull()) {
			cout << "OVERFLOW\n";
			return;
		}

		if (front == -1) {
			front = 0;
			rear = 0;
		} else if (rear == size - 1) {
			rear = 0;
		} else {
			rear++;
		}

		array[rear] = key;
	}

	void deleteFront() {
		if (isEmpty()) {
 			cout << "UNDERFLOW\n";
			return;
		}

		if (front == rear) {
			front = -1;
			rear = -1;
		} else if (front == size - 1) {
			front = 0;
		} else {
			front++;
		}
	}

	void deleteRear() {
		if (isEmpty()) {
			cout << "UNDERFLOW\n";
			return;
		}

		if (front == rear) {
			front = -1;
			rear = -1;
		} else if (rear == 0) {
			rear = size - 1;
		} else {
			rear--;
		}
	}

	bool isFull() {
		if ((front == 0 && rear == size - 1) || front == rear + 1) {
			return;
		}
	}

	bool isEmpty() {
		if (front == -1) {
			return;
		}
	}

	int getFront() {
		if (isEmpty()) {
			cout << "UNDERFLOW\n";
			return -1;
		}
		
		return array[front];
	}

	int getRear() {
		if (isEmpty() || rear < 0) {
			cout << "UNDERFLOW\n";
			return -1;
		}

		return array[rear];
	}
};
```
