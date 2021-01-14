### Min Heap Construction
> Implement a MinHeap class that supports:<br/>
> - Building a Min Heap from an input array of integers <br/>
> - Inserting integers in the heap<br/>
> - Removing the heap's minimum/root value<br/>
> - Peeking at the heap's minimum/root value<br/>
> - Sifting integers up and down the heap, which is to be used when inserting and removing values<br/>
\
\
> NOTE: the heap should be represented in the form of an array

### Input: Output
```
array = [48, 12, 24, 7, 8, -5, 24, 391, 24, 56, 2, 6, 8, 41]

// All below operations are performed sequentially
MinHeap(array): -   // instantiate a MinHeap (calls the buildHeap method and populates the heap)
buildHeap(arra): -  // [-5, 2, 6, 7, 8, 8, 24, 391, 24, 56, 12, 24, 48, 41]
insert(76): -       // [-5, 2, 6, 7, 8, 8, 24, 391, 24, 56, 12, 24, 48, 41, 76]
peak(): -5
remove(): -5        // [2, 7, 6, 24, 8, 8, 24, 391, 76, 56, 12, 24, 48, 41]
peek(): 2
remove(): 2         // [6, 7, 8, 24, 8, 24, 24, 391, 76, 56, 12, 41, 48]
peek(): 6
insert(87): -       // [6, 7, 8, 24, 8, 24, 24, 391, 76, 56, 12, 41, 48, 87]
```

### Solution 
For the buildHeap(), remove(), and insert() methods of the Heap, create a siftDown() and siftUp() methods. These sifting methods allow you to take any node in the heap and move it either up or down until the node is in its appropriate position.
```cpp
class MinHeap {
public:
	vector<int> heap;

	MinHeap(vector<int> vector) {
		heap = bildHeap(vector);
	}
	...
};
```

To build-up the heap, either sift every node in the input array *down* or *up* to its final, correct position. Finally, return the heapified vector.
```cpp
	...
	vector<int> buildHeap(vector<int> &vector) {
		int firstParentIdx = (vector.size() - 2) / 2;

		for (int currentIdx = firstParentIdx; currentIdx >= 0; currentIdx--) {
			siftDown(currentIdx, vector.size() - 1, vector);   // can sift-up or sift-down
		}

		return vector;
	}
	...
```
In an array-based heap, access a node's children nodes and parent node byu using the nodes' indices. 
\
\
To *sift-down* nodes of the heap, compare the node in question to its child nodes. If a node is located at index *i*, then its children nodes are located at indices *2 * i + 1* and *2 * i + 2*.
```cpp
	...
	void siftDown (int currentIdx, int endIdx, vector<int> &heap) {
		int childOneIdx = currentIdx * 2 + 1;

		while (childOneIdx <= endIdx) {
			int childTwoIdx = currentIdx * 2 + 2  <= endIdx ? currentIdx * 2 + 2 : -1;
			int idxToSwap;

			if (childTwoIdx != -1 && heap[childTwoIdx] < heap[childOneIdx]) {
				idxToSwap = childTwoIdx;
			} else {
				idxToSwap = childOneIdx;
			}

			if (heap[idxToSwap] < heap[currentIdx]) {
				swap(heap[currentIdx], heap[idxToSwap]);
				currentIdx = idxToSwap;
				childOneIdx = currentIdx * 2 + 1;
			} else {
				return;
			}
		}
	}
	...
```

To sift-up nodes of the heap, compare the node in question to its parent node. If a node is located at index *i*, then its parent node is located at index *Math.floor((i - 1) / 2)*.
```cpp
	...
	void siftUp(int currentIdx) {
		int parentIdx = (currentIdx - 1) / 2;

		while (currentIdx > 0 && heap[currentIdx] < heap[parentIdx]) {
			swap(heap[currentIdx], heap[parentIdx]);
			currentIdx = parentIdx;
			parentIdx = (currentIdx - 1) / 2;
		}
	}
	...
```

To take a look at the element with the longest wait (or highest priority), access the *first* element of the heap.
```cpp
	...
	int peak() {
		return heap[0];
	}
	...
```

To remove the element next-in-line (or in-priority), first swap the first-in-line (longest wait) element with the last-in-line (most recetly added) element. Then ... and sift-down. Finally, return the previously first-in-line (longest wait) element.
```cpp
	...
	int remove() {
		swap(heap[0], heap[heap.size() - 1]);
		int result = heap.back();
		heap.pop_back();
		siftDown(0, heap.size() - 1, heap); 

		return result;
	}
	...
```

To insert a new element, first add the new element to the *rear* of the queue, then sift-up.
```cpp
	...
	void insert(int number) {
		heap.push_back(number);    // add value to end-of-line (rear of queue)
		siftUp(heap.size() - 1); 
	}
	...
```

### Complexity Analysis
Build the Heap: O(n) Time | O(1) Space<br/>
Sifting: O(log n) Time | O(1) Space
