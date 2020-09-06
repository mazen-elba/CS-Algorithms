BST Traversal

Write three functions that take a BST and an empty array, traverse the BST, add its nodes' values to the input array, and return that array. The three functions should traverse the BST using the in-order, pre-order, and post-order tree-traversal techniques, respectively.

INPUT
tree = 10
/ \
 5 15
/ \ \
 2 5 22
/
1
array = []

OUTPUT
inOrderTraverse = [1, 2, 5, 5, 10, 15, 22]
preOrderTraverse = [10, 5, 2, 1, 5, 15, 22]
postOrderTraverse = [1, 2, 5, 5, 22, 15, 10]
