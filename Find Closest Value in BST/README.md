### Find Closest Value in BST
> Write a function that takes in a Binary Search Tree (BST) and a target integer value and returns the closest value to that target value contained in the BST. <br/>

> Assume that there will only be one closest value.<br/>

> Each _BST_ node has an integer _value_, a _left_ child node, and a _right_ child node. A node is said to be a valid _BST_ node if an only if it satisfies the BST property: its _value_ is strictly greater than th values of every node to its left; its _value_ is less than or equal to the values of every node to its right; and its children nodes are either valie _BST_ nodes themselves or _None_/_null_.

### Input
tree = 10 <br/>
/\ <br/>
5 15 <br/>
/\/\ <br/>
2 5 13 22 <br/>
/\ <br/>
1 14 <br/>
target = 12

### Output
13

### Solution (recursive)
Traverse the BST node by node, all the while keeping track of the node with the value closest to the target value. <br/>

Calculate the aboslute value of the difference between a node's value should allow you to check if that node is closer than the current closest one. <br/>

Use the BST properties to determine what side of any given node has values close to the target value and is therefore worth exploring.

### Optimal Complexity
Average: O(log(n)) Time | O(log(n))  Space
Worst: O(n) Time | O(n) Space

### Data Structure - BST (C/C++)