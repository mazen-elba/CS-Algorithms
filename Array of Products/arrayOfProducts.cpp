#include <vector>

using namespace std;

vector<int> arrayOfProducts(vector<int> array) {
	vector<int> productArray(array.size(), 1);

	int leftCurrentProduct = 1;
	for (int i = 0; i < array.size(); i++) {
		productArray[i] = leftCurrentProduct;
		leftCurrentProduct *= array[i];
	}

	int rightCurrentProduct = 1;
	for (int i = array.size() - 1; i >= 0; i--) {
		productArray[i] *= rightCurrentProduct;
		rightCurrentProduct *= array[i];
	}

	return productArray;
}
