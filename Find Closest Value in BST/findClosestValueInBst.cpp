#include <cmath>
#include <float.h>

using namespace std;

class BST {
    public:
    int value;
    BST *left;
    BST *right;

    BST(int val);
    BST &insert(int val);
};

int findClosestValueInBst(BST *tree, int target);
int helper(BST *tree, int target, int closest);

int findClosestValueInBst(BST *tree, int target) {
    return helper(tree, target, tree->value);
}

int helper(BST *tree, int target, int closest) {
    if (abs(target - closest) > abs(target - tree->value)) {
        closest = tree->value;
    }

    if (target < tree->value && tree->left !=NULL) {
        return helper(tree->left, target, closest);
    } else if (target > tree->value && tree->right !=NULL) {
        return helper(tree->right, target, closest);
    } else {
        return closest;
    }
}