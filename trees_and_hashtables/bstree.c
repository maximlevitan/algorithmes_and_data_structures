#include <stdio.h>
#include <stdlib.h>

#include "structures.h"

BSTree createNewBSTree()
{
    BSTree tree;

    tree.root = NULL;
    tree.size = 0;

    tree.insert = &insertBSTreeNode;

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
