BST Construction

Write a BST class for a BST. The class should support:

- Inserting values with the insert method
- Removing values with the remove method; this method should only remove the first instance of a given value
- Searching for values with the contains method

Note: cannot remove values from a single-node tree.

GIVEN
tree = 10
/ \
 5 15
/ \ / \
 2 5 13 22
/ \
 1 14

INPUT
insert(12)
remove(10)
contains(15)

OUTPUT
insert(12): 10
/ \
 5 15
/ \ / \
 2 5 13 22
/ / \
 1 12 14

remove(10): 12
/ \
 5 15
/ \ / \
 2 5 13 22
/ \
 1 14

contains(15): true
