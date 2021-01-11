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

* Basic Operations (LIFO or FILO):
	* Push - adds an item in the stack; if stack is *full*, it is an *overflow* condition
	* Pop - removes an item from the stack; items are popped in reverse order in which they are pushed; if stack is *empty*, it is an *underflow* condition
	* Peek/Top - returns top element of stack
	* isEmpty - return *true* if stack is empty; otherwise, returns *false*
	* isFull - check if the stack is full

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

* Array Implementation
```cpp
class Stack {
	int top;

public: 
	int a[MAX];   // maximum size of stack

	Stack() {
		top = -1;
	}

	bool push(int x);
	int pop();
	int peek();
	bool isEmpty();
};

bool Stack::push(int x) {
	if (top >= (MAX - 1)) {
		return false;   // stack overflow
	} else {
		a[++top] = x;   // push x into stack
		return true;
	}
}

int Stack::pop() {
	if (top < 0) {
		return 0;   // stack underflow 
	} else {
		int x = a[top--];
		return x;
	}
}

int Stack::peek() {
	if (top < 0) {
		return 0;   // stack is empty
	} else {
		int x = a[top];
		return x;
	}
}

bool Stack::isEmpty() {
	return top < 0;
}
```

* Linked List Implementation
```cpp
class StackNode {
public: 
	int data;
	StackNode* next;
};

StackNode* newNode(int data) {
	StackNode* stackNode = new StackNode();
	stackNode->data = data;
	stackNode->next = NULL;
	return stackNode;
}

int isEmpty(StackNode* root) {
	return !root;
}

void push(StackNode** root, int data) {
	StackNode* stackNode = newNode(data);   // data pushed to stack
	stackNode->next = *root;
	*root = stackNode;
}

int pop(StackNode** root) {
	if (isEmpty(*root)) {
		return INT_MIN;
	}

	StackNode* temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	free(temp);

	return popped;
}

int peek(StackNode* root) {
	if (isEmpty(root)) {
		return INT_MIN;
	}

	return root->data;
}
```

# Queues

* Basic Operations (FIFO):
	* Enqueue - adds an item to the queue; if the queue is *full*, it is an *overflow* condition
	* Dequeue - removes an item from the queue; items are popped in the same order in which they are pushed; if the queue is *empty*, it is an *underflow* condition
	* Front - get the first item (in line) from queue
	* Rear - get the last item (in line) from the queue
	* isEmpty - check if the queue is empty
	* isFull - check if the queue is full
	* Peek/Top - return the value of the *front* of the queue (without removing it)

* Implementation (insertion/deletion happen on *different* ends)
	* Keep track of two indices: rear and front
	* Increment rear and front in *circular* motion
	* Items are *enqueued* at the rear
	* Items are *dequeued* from the front

* How a Queue Works:
	* Two poitners FRONT and REAR
	* FRONT tracks the first element of the queue
	* REAR tracks the last element of the queue
	* Initially, set the values of FRONT and REAR to -1
	* Enqueue
		* Check if the queue is full
		* For the first element, set the value of FRONT to 0
		* Increase the REAR index by 1
		* Add the new element in the poisition pointed to by REAR
	* Dequeue
		* Check if the queue is empty
		* Return the value pointed by FRONT
		* Increase the FRONT index by 1
		* For the last element, reset the values of FRONT and REAR to -1
```cpp
class Queue {
public:
	int front, rear, size;
	unsigned capacity;
	int* array;
};

Queue* createQueue(unsigned capacity) {
	Queue* queue = new Queue();
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = capacity - 1;   // enqueue designation
	queue->array = new int[(queue->capacity * sizeof(int))];

	return queue;
}

int isFull(Queue* queue) {
	return queue->size == queue->capacity;   // queue is full when size equals to capacity
}

int isEmpty(Queue* queue) {
	return queue->size == 0;   // queue is empty when size is 0
}

void enqueue(Queue* queue, int item) {
	if (isFull(queue)) {
		return;
	}

	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;   // item enqueued to queue
	queue->size = queue->size + 1;
}

int dequeue(Queue* queue) {
	if (isEmpty(queue)) {
		return INT_MIN;
	}

	int item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size = queue->size - 1;

	return item;   // item dequeued from queue
}

int front(Queue* queue) {
	if (isEmpty(queue)) {
		return INT_MIN;
	}

	return queue->array[queue->front];
}

int rear(Queue* queue) {
	if (isEmpty(queue)) {
		return INT_MIN;
	}

	return queue->array[queue->rear];
}
```

### Priority Queues (an extension of queue)

* A priority queue is a queue that does not have the FIFO logic (jumps the line)
	* Can add successive pieces of data and retrieve the one with "highest priority" in O(1) Time

* To implement a priority queue, need a comparison between its elements (to determine priority)

* Properties:
	* Every item has a priority associated with it
	* An element with high priority is *dequeued* before an element with low priority
	* If two element have the *same* priority, they are served according to their order in queue
	* An element with maximum ASCII value will have highest priority

* Basic Operations:
	* Push(item, priority) - adds an item with given priority
		* Implemented by adding an item at the end of array in O(1) Time
	* Peek/Top() - returns the highest priority item
		* Implemented by linearly searching the highest priority item in array in O(n) Time
	* Pop() - removes the highest priority item
		* Implemented by first linearly searching an item, then removing the item by moving all subsequent items one position back

* Implementation
	* Pros: unlike a regular queue, nodes are given weight, which allows them to move towards the head of the queue (rather than being on the tail)
	* Cons: unlike a regular queue, insertion doesn't take a constant time (due to applying insertion sort, and priority)
	* Using an array
	* Using a linked list
	* Using a heap (preferred) 
		* Heaps are an implementation of priority queues

* Array Implementation
```cpp
struct node {   // node declaration
	int priority; 
	int item;
	struct node *l;
};

class Priority_Queue {
private:
	node *frontPtr;   // declare a front pointer

public:
	Priority_Queue() {   // constructor
		frontPtr = NULL;
	}

	void push(int item, int priority) {
		node *t, *q;
		t = new node;
		t->item = item;
		t->priority = priority;

		if (frontPtr == NULL || priority < frontPtr->priority) {
			t->l = frontPtr;
			frontPtr = t;
		} else {
			q = frontPtr;
			
			while (q->l != NULL && q->l->priority <= priority) {
				q = q->l;
				t->l = q->l;
				q->l = t;
			}
		}
	}

	void pop() {   // deletes the highest priority item
		node *t;

		if (frontPtr == NULL) {   // if queue is empty
			cout << "Queue Underflow\n";
		} else {
			t = frontPtr;
			frontPtr = frontPtr->l;
			free(t);
		}
	}

	void peek() {
		node *ptr;
		ptr = frontPtr;
		if (frontPtr == NULL) {
			cout << "Queue is empty\n";
		} else {
			while (ptr != NULL) {
				ptr = ptr->l;
			}
		}
	}
};
```
