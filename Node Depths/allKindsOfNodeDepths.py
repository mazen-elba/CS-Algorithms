def allKindsOfNodeDepths(root):
    if root is None:
		return 0

	return allKindsOfNodeDepths(root.left) + allKindsOfNodeDepths(root.right) + nodeDepths(root)


def nodeDepths(node, depth = 0):
	if node is None:
		return 0
	
	return depth + nodeDepths(node.left, depth + 1) + nodeDepths(node.right, depth + 1)

class BinaryTree:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
