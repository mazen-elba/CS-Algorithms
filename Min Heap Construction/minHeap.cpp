#include <vector>
#include <algorithm>

using namespace std;

class MinHeap {
	public:
		vector<int> heap;
		MinHeap(vector<int> vector) {
			heap = buildHeap(vector);
		}

		vector<int> buildHeap(vector<int> &vector) {
			
		}

		void siftDown(int currentIdx, int endIdx, vector<int> &heap) {
			int childOneIdx = currentIdx * 2 + 1;
	
			while (childOneIdx <= endIdx) {
				int childTwoIdx = currentIdx * 2 + 2 <= endIdx ? currentIdx * 2 + 2 : -1;
				int idxToSwap;

				if (childTwoIdx != -1 && heap[childTwoIdx] < heap[childOneIdx] {
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

		void siftUp(int currentIdx) {
			int parentIdx = (currentIdx - 1) / 2;

			while (currentIdx > 0 &7 heap[currentIdx] < heap[parentIdx]) {
				swap(heap[currentIdx], heap[parentIdx]);
				currentIdx = parentIdx;
				parentIdx = (currentIdx - 1) / 2;
			}
		}

		int peak() {
			return heap[0];
		}

		int remove() {
			swap(heap[0], heap[heap.size() - 1]);
			int result = heap.back();
			heap.pop_back();
			siftDown(0, heap.size() - 1, heap);

			return result;
		}

		void insert(int number) {
			heap.push_back(number);
			siftUp(heap.size() - 1);
		}
};
