function nodeDepths(node, depth = 0) {
  if (node === null) {
    return 0;
  }

  return (
    depth + nodeDepths(node.left, depth + 1) + nodeDepths(node.right, depth + 1)
  );
}

class BinaryTree {
  constructor(value) {
    this.value = value;
    this.left = null;
    this.right = null;
  }
}

exports.allKindsOfNodeDepths = allKindsOfNodeDepths;
