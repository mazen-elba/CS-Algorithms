using namespace std;

int longestPeak(vector<int> array) {
	int maxPeakLength = 0;
	int i = 1;
	
	while (i < int(array.size() - 1)) {
		bool isPeak = array[i-1] < array[i] && array[i] > array[i+1];
		if (!isPeak) {
			i++;
			continue;
		}

		int leftIdx = i - 2;
		while (leftIdx >= 0 && array[leftIdx] < array[leftIdx+1]) {
				leftIdx--;
		}

		int rightIdx = i + 1;
		while (rightIdx < array.size() && array[rightIdx] < array[rightIdx-1]) {
			rightIdx++;
		}

		int currentPeakLength = rightIdx - leftIdx - 1;
		maxPeakLength = max(maxPeakLength, currentPeakLength);
		i = rightIdx;
	}
	
	return maxPeakLength;
}
