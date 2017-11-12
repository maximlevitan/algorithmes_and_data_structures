#include <stdio.h>
#include <stdlib.h>

#include "structures.h"

BSTree createNewBSTree()
{
    BSTree tree;

    tree.root = NULL;
    tree.size = 0;

    tree.insert = &insertBSTreeNode;
    tree.delete = &deleteBSTreeNode;

    return tree;
}

TreeNode* getBSTreeFreeNode(BSTree* tree, T value, TreeNode* parent)
{
    TreeNode* tmp = (TreeNode*) malloc(sizeof(TreeNode));
    if (tmp == NULL) {
        tree->lastError = ERROR_NODE_MALLOC;
        tree->hasError = 1;

        return tmp;
    }

    tmp->left = tmp->right = NULL;
    tmp->value = value;
    tmp->parent = parent;

    return tmp;
}

void insertBSTreeNode(BSTree* tree, T value)
{
    tree->lastError = "";
    tree->hasError = 0;

    TreeNode *tmp = NULL;
    if (tree->root == NULL) {
        tree->root = getBSTreeFreeNode(tree, value, NULL);

        return;
    }

    tmp = tree->root;
    while (tmp) {
        if (value > tmp->value) {
            if (tmp->right) {
                tmp = tmp->right;

                continue;
            } else {
                tmp->right = getBSTreeFreeNode(tree, value, tmp);

                return;
            }
        } else if (value < tmp->value) {
            if (tmp->left) {
                tmp = tmp->left;

                continue;
            } else {
                tmp->left = getBSTreeFreeNode(tree, value, tmp);

                return;
            }
        } else {
            tree->lastError = "Wrong built tree";
            tree->hasError = 1;
        }
    }
}

void deleteBSTreeNode(BSTree* tree, T value)
{
    tree->lastError = "";
    tree->hasError = 0;

    if (tree->root == NULL) {
        return;
    }

    TreeNode* removedNode;

    if (tree->root->value == value) {
        TreeNode* auxRoot = getBSTreeFreeNode(tree, 0, NULL);

        auxRoot->left = tree->root;
        removedNode = removeBSTreeFreeNode(tree->root, value, auxRoot);
        tree->root = auxRoot->left;

        if (removedNode != NULL) {
            free(removedNode);
        }
    } else {
        removedNode = removeBSTreeFreeNode(tree->root, value, NULL);

        if (removedNode != NULL) {
            free(removedNode);
        }
    }

    return;
}

TreeNode* removeBSTreeFreeNode(TreeNode* selfNode, T value, TreeNode* parent)
{
    if (value < selfNode->value) {
        if (selfNode->left != NULL) {
            return removeBSTreeFreeNode(selfNode->left, value, selfNode);
        } else {
            return NULL;
        }
    } else if (value > selfNode->value) {
        if (selfNode->right != NULL) {
            return removeBSTreeFreeNode(selfNode->right, value, selfNode);
        } else {
            return NULL;
        }
    } else {
        if (selfNode->left != NULL && selfNode->right != NULL) {
            selfNode->value = minBSTreeNodeValue(selfNode->right);

            return removeBSTreeFreeNode(selfNode->right, selfNode->value, selfNode);
        } else if (parent->left == selfNode) {
            parent->left = (selfNode->left != NULL) ? selfNode->left : selfNode->right;

            return selfNode;
        } else if (parent->right == selfNode) {
            parent->right = (selfNode->left != NULL) ? selfNode->left : selfNode->right;

            return selfNode;
        }
    }

    return NULL;
}

T minBSTreeNodeValue(TreeNode* selfNode)
{
    if (selfNode->left == NULL) {
        return selfNode->value;
    } else {
        return minBSTreeNodeValue(selfNode->left);
    }
}

void preOrderTraversalTreePrint(TreeNode* root)
{
    if (!root) {
        return;
    }

    printf("%d ", root->value);

    preOrderTraversalTreePrint(root->left);
    preOrderTraversalTreePrint(root->right);
}

void inOrderTraversalTreePrint(TreeNode* root)
{
    if (!root) {
        return;
    }

    inOrderTraversalTreePrint(root->left);

    printf("%d ", root->value);

    inOrderTraversalTreePrint(root->right);
}

void postOrderTraversalTreePrint(TreeNode* root)
{
    if (!root) {
        return;
    }

    postOrderTraversalTreePrint(root->left);
    postOrderTraversalTreePrint(root->right);

    printf("%d ", root->value);
}

// Распечатка двоичного дерева в виде скобочной записи
void printTree(TreeNode* root)
{
    if (root) {
        printf("%d", root->value);

        if (root->left || root->right) {
            printf("(");

            if (root->left) {
                printTree(root->left);
            } else {
                printf("NULL");
            }

            printf(",");

            if (root->right) {
                printTree(root->right);
            } else {
                printf("NULL");
            }

            printf(")");
        }
    }
}
