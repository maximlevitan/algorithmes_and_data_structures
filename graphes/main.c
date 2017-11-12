/**
 * Graphes
 *
 * @author Maxim Levitan <maximlevitan@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helpers.h"
#include "structures.h"
#include "graph.h"

int main(int argc, const char* argv[])
{
    int result = 0;

    if (argc < 2) {
        printf("Incorrect command: required file name as first argument.\n");
        printf("Second argument is order traversal type, possible values: ");
        printf("1 - pre-order, 2 - in-order, 3 - post-order.\n");

        return result;
    }

    int* matrix;
    int matrixSize = 0;
    FILE* inputFile = fopen(argv[1], "r");

    matrixSize = loadAdjacencyMatrixData(inputFile, &matrix);

    if (matrixSize < 0) {
        puts("Can't load data!");

        result = 1;
    } else if (matrixSize == 0) {
        puts("Empty matrix");

        result = 2;
    }

    fclose(inputFile);

    if (result > 0) {
        return result;
    }

    printAdjacencyMatrix((int*) matrix, matrixSize);

    graphMatrixDFS(5, (int*) matrix, matrixSize);

    puts("\nGoodbye!");

    return result;
}
