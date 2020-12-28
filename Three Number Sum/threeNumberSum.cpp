#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
	sort(array.begin(), array.end());
	vector<vector<int>> triplets;

	for (int i = 0; i < array.size() - 2; i++){
		int leftIdx = i + 1;
		int rightIdx = array.size() - 1;

		while (leftIdx < rightIdx){
			int currentSum = array[i] + array[leftIdx] + array[rightIdx];

			if (currentSum == targetSum) {
				triplets.push_back({array[i], array[leftIdx], array[rightIdx]});
				leftIdx++;
				rightIdx--;
			} else if (currentSum < targetSum) {
				leftIdx++;
			} else if (currentSum > targetSum) {
				rightIdx--;
			}
		}
	}

	return triplets;
}
