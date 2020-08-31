Depth-First Search

Given a Node class that has a name and an array of optional children nodes. When put together, nodes form an acyclic tree-like structure.

Implement DPF method on the Node class, which takes an empty array, traverses the tree using DFS approach (navigating tree fro mleft to right), stores all of the nodes' names in the input array, and returns it.

INPUT
graph = A
/ | \
 B C D
/ \ / \
 E F G H
/ \ \
 I J K

OUTPUT
["A", "B". "E", "F", "I", "J", "C", "D", "G", "K", "H"]
