#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int>> fourNumberSum(vector<int> array, int targetSum) {
	unordered_map<int, vector<vector<int>>> pairSums;
	vector<vector<int>> quadruplets{};

	for (int i = 1; i < array.size() - 1; i++) {
		for (int j = i + 1; j < array.size(); j++) {
			int currentSum = array[i] + array[j];
			int sumDiff = targetSum - currentSum;

			if (pairSums.find(sumDiff) != pairSums.end()) {
				for (vector<int> pair : pairSums[sumDiff]) {
					pair.push_back(array[i]);
					pair.push_back(array[j]);
					quadruplets.push_back(pair);
				}
			}
		}

		for (int k = 0; k < i; k++) {
			int currentSum = array[i] + array[k];

			if (pairSums.find(currentSum) == pairSums.end()) {
				pairSums[currentSum] = vector<vector<int>>{{array[k], array[i]}};
			} else {
				pairSums[currentSum].push_back(vector<int>{array[k], array[i]});
			}
		}
	}

	return quadruplets;
}
