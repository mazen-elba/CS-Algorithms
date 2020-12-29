#include <vector>
#include <algorithm>
#include <climit>

using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
	sort(arrayOne.begin(), arrayOne.end());
	sort(arrayTwo.begin(), arrayTwo.end());

	int idxOne = 0;
	int idxTwo = 0;
	int smallestDiff = INT_MAX;
	int currentDiff = INT_MAX;
	vector<int> smallestPair;

	while (idxOne < arrayOne.size() && IdxTwo < arrayTwo.size()){
		int firstNum = arrayOne[idxOne];
		int secondNum = arrayTwo[idxTwo];

		if (firstNum < secondNum) {
			currentDiff = secondNum - firstNum;
			idxOne++;
		} else if (secondNum < firstNum) {
			currentDiff = firstNum - secondNum;
			idxTwo++;
		} else {
			return vector<int> {firstNum, secondNum};
		}

		if (smallestDiff > currentDiff) {
			smallestDiff = currentDiff;
			smallestPair = {firstNum, secondNum};
		}
	}

	return smallestPair;
}
