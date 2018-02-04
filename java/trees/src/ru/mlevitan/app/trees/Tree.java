package ru.mlevitan.app.trees;

public class Tree<T> {

    private class TreeNode<E> {

        public int key;
        public E value;

        public TreeNode<E> leftChild;
        public TreeNode<E> rightChild;

        public TreeNode(int key, E value) {
            this.key = key;
            this.value = value;
        }

        @Override
        public String toString() {
            return value.toString();
        }

    }

    private TreeNode<T> root;

    public TreeNode<T> getNode(T object) {
        int objectKey = object.hashCode();
        TreeNode<T> current = root;

        while (current.key != objectKey) {
            if (objectKey < current.key) {
                current = current.leftChild;
            } else {
                current = current.rightChild;
            }

            if (current == null) {
                return null;
            }
        }

        return current;
    }

    public void insert(T object) {
        int objectKey = object.hashCode();
        TreeNode<T> node = new TreeNode<>(objectKey, object);

        if (root == null) {
            root = node;
        } else {
            TreeNode<T> foundNode = getNode(object);
            if (foundNode != null) {
                foundNode.value = object;
                return;
            }

            TreeNode<T> current = root;
            TreeNode<T> parent;
            while (true) {
                parent = current;
                if (objectKey < current.key) {
                    current = current.leftChild;
                    if (current == null) {
                        parent.leftChild = node;
                        return;
                    }
                } else {
                    current = current.rightChild;
                    if (current == null) {
                        parent.rightChild = node;
                        return;
                    }
                }
            }
        }
    }

    private void inOrderTravers(TreeNode<T> currentNode) {
        if (currentNode != null) {
            inOrderTravers(currentNode.leftChild);
            System.out.println(currentNode + ", ");
            inOrderTravers(currentNode.rightChild);
        }
    }

    public void displayTree() {
        inOrderTravers(root);
    }

    public TreeNode<T> min() {
        TreeNode<T> current = root;
        TreeNode<T> last = null;
        while (current != null) {
            last = current;
            current = current.leftChild;
        }

        return last;
    }

    public boolean delete(T object) {
        TreeNode<T> current = root;
        TreeNode<T> parent = root;
        boolean isLeftChild = true;

        int objectKey = object.hashCode();

        // search
        while (current.key != objectKey) {
            parent = current;
            if (objectKey < current.key) {
                isLeftChild = true;
                current = current.leftChild;
            } else {
                isLeftChild = false;
                current = current.rightChild;
            }

            if (current == null) {
                return false;
            }
        }

        // leaf
        if (current.leftChild == null && current.rightChild == null) {
            if (current == root) {
                root = null;
            } else if (isLeftChild) {
                parent.leftChild = null;
            } else {
                parent.rightChild = null;
            }
        } else if (current.rightChild == null) { // if only one child = make him successor
            if (isLeftChild) {
                parent.leftChild = current.leftChild;
            } else {
                parent.rightChild = current.leftChild;
            }
        } else if (current.leftChild == null) {
            if (isLeftChild) {
                parent.leftChild = current.rightChild;
            } else {
                parent.rightChild = current.rightChild;
            }
        } else { // if node has two children
            TreeNode<T> successor = getSuccessor(current);

            if (current == root) {
                root = successor;
            } else if (isLeftChild) {
                parent.leftChild = successor;
            } else {
                parent.rightChild = successor;
            }

            successor.leftChild = current.leftChild;
        }

        return true;
    }

    private TreeNode<T> getSuccessor(TreeNode<T> node) {
        TreeNode<T> parent = node;
        TreeNode<T> successor = node;
        TreeNode<T> current = node.rightChild;

        while (current != null) {
            parent = successor;
            successor = current;
            current = current.leftChild;
        }

        if (successor != node.rightChild) {
            parent.leftChild = successor.rightChild;
            successor.rightChild = node.rightChild;
        }

        return successor;
    }

}
