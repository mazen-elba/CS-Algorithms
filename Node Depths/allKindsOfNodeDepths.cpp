using namespace std;

class BinaryTree
{
public:
    int value;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int value)
    {
        this->value = value;
        left = NULL;
        right = NULL;
    }
};

int nodeDepths(BinaryTree *node, int depth = 0);

int nodeDepths(BinaryTree *node, int depth)
{
    if (node == NULL)
    {
        return 0;
    }

    return depth + nodeDepths(node->left, depth + 1) + nodeDepths(node->right, depth + 1);
}