All Kinds of Node Depths

Node's Depth is the distance between a node in a Binary Tree and the tree's root.

Write a function that takes a Binary Tree and returns the sum of all of its subtrees' nodes' depths.

INPUT
tree = 1
/ \
 2 3
/ \ / \
 4 5 6 7
/ \  
 8 9

OUTPUT
26
// sum of the root tree's node depths is 16
// sum of the tree rooted at 2's node depths is 6
// sum of the tree rooted at 3's node depths is 2
// sum of the tree rooted at 4's node depths is 2
// summing all of these sums yields 26
