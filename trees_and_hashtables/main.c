/**
 * Data structures: tree, hashtable
 *
 * @author Maxim Levitan <maximlevitan@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helpers.h"
#include "structures.h"

int main(int argc, const char* argv[])
{
    int orderTraversalType = 2; // by default in-order traversal

    if (argc < 2) {
        printf("Incorrect command: required file name as first argument.\n");
        printf("Second argument is order traversal type, possible values: ");
        printf("1 - pre-order, 2 - in-order, 3 - post-order.\n");

        return 0;
    }

    if (argc > 2) {
        orderTraversalType = atoi(argv[2]);

        orderTraversalType = (orderTraversalType > 3 || orderTraversalType < 1) ? 2 : orderTraversalType;
    }

    FILE* file = fopen(argv[1], "r");

    if (file == NULL) {
        puts("Can't open file!");

        return 1;
    }

    int count;
    fscanf(file, "%d", &count); // Считываем количество записей

    BSTree tree = createNewBSTree();

    int i;
    for (i = 0; i < count; i++) {
        int value;

        if (fscanf(file, "%d", &value) == EOF) {
            break;
        }

        tree.insert(&tree, value);
    }

    fclose(file);

    printTree(tree.root);

    switch (orderTraversalType) {
        case 1:
            printf("\nPreOrderTravers: ");
            preOrderTraversalTreePrint(tree.root);
            break;

        case 3:
            printf("\nPostOrderTravers: ");
            postOrderTraversalTreePrint(tree.root);
            break;

        case 2:
        default:
            printf("\nInOrderTravers: ");
            inOrderTraversalTreePrint(tree.root);
    }

    // Get hash sum of string
    char* testString = "Hello world!";
    printf("\n\nHash sum of '%s' = %d\n", testString, hashSumString(testString));

    puts("Goodbye!");

    return 0;
}
