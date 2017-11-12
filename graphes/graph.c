/**
 * @author Maxim Levitan <maximlevitan@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
#include "graph.h"

int loadAdjacencyMatrixData(FILE* inputFile, int** matrix)
{
    int size, i, j;

    if (inputFile == NULL) {
        return -1;
    }

    fscanf(inputFile, "%i", &size); // Считываем количество записей

    // Формируем динамическую матрицу
    *matrix = (int*) malloc(size * size * sizeof(int));
    if (*matrix == NULL) {
        return -1;
    }

    while (!feof(inputFile)) {
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                int weight;
                fscanf(inputFile,"%i", &weight);

                *((*matrix + i * size) + j) = (weight < MAX_MATRIX_INT_VALUE) ? weight : 0;
            }
        }

        break;
    }

    return size;
}

void printAdjacencyMatrix(int* matrix, int size)
{
    printf("Adjacency matrix with size of %d nodes:\n", size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%6i", *((matrix + i * size) + j));
        }

        puts("");
    }
}

/**
 * DFS (Depth-first search) - обход графа в глубину
 */
void graphMatrixDFS(int firstVertexPosition, int* matrix, int size)
{
    int i, vertex, delta, deltaTranc;

    if (firstVertexPosition < 0 || firstVertexPosition >= size) {
        printf("Unexisted first vertex position.\n");

        return;
    }

    int* marked = (int*) malloc(size * size * sizeof(int));
    if (marked == NULL) {
        printf("Can`t allocate some dynamic memory for marked array.\n");

        return;
    }

    Stack stack = createNewStack(size);

    stack.push(&stack, firstVertexPosition);
    while (stack.size > 0) {
        vertex = stack.pop(&stack);

        for (i = 0; i < size; i++) {
            delta = vertex * size + i;
            deltaTranc = vertex + i * size;

            if (*(marked + delta) == 0) {
                if (*(matrix + delta) != -1) {
                    stack.push(&stack, i);

                    printf("(%d,%d)\n", vertex+1, i+1);
                }

                *(marked + delta) = 1;
                *(marked + deltaTranc) = 1;
            }
        }
    }
}
