#include <vector>
#include <algorithm>

using namespace std;

int firstDuplicateValue(vector<int> array) {
	int minSecondIdx = array.size();

	for (int i = 0; i < array.size(); i++) {
		for (int j = i + 1; j < array.size(); j++) {
			if (array[i] == array[j]) {    // IF value == valueToCompare ? TRUE
				minSecondIdx = min(minSecondIdx, j);
			}
		}
	}

	if (minSecondIdx == array.size()) {
		return -1;  // edge case: no duplicates
	}

	return array[minSecondIdx];
}
