/**
 * @author Maxim Levitan <maximlevitan@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
#include "helpers.h"
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
void graphFullDFS(int firstVertex, int* matrix, int size)
{
    int j, vertex, weight;
    int depth = 0;
    int maxDepth = 0;
    int needContinue;

    if (firstVertex < 0 || firstVertex >= size) {
        printf("Unexisted first vertex number.\n");

        return;
    }

    int* marked = (int*) malloc(size * sizeof(int));
    if (marked == NULL) {
        printf("Can`t allocate some dynamic memory for marked array.\n");

        return;
    }

    fillArrayIntByValue(marked, size, 0);

    Stack stack = createNewStack(size);

    stack.push(&stack, firstVertex);
    *(marked + firstVertex) = 1;

    puts("\nGraph full DFS demo.");
    printf("Matrix size: %dx%d; first vertex number: %d", size, size, firstVertex);

    while (stack.size > 0) {
        needContinue = 0;

        if (depth > maxDepth) {
            maxDepth = depth;
        }

        vertex = stack.pop(&stack);

        printf("\nV(%d)", vertex);

        for (j = 0; j < size; j++) {
            if (*(marked + j) == 0) {
                weight = *((matrix + vertex * size) + j);
                if (weight != -1) {
                    *(marked + j) = 1;

                    stack.push(&stack, j);

                    // Визуализируем пути
                    printf(" --E(W:%d)-> V(%d) ", weight, j);

                    depth++;

                    needContinue = 1;
                    break;
                }
            }
        }

        if (needContinue > 0) {
            continue;
        }

        depth--;
    }

    printf("\nMax graph tree height (depth): %d\n", maxDepth);
}

/**
 * BFS (Breadth-first search) - обход графа в ширину
 */
void graphFullBFS(int firstVertex, int* matrix, int size)
{
    int j, vertex, weight;
    int depth = 0;
    int maxDepth = 0;
    int needContinue;

    if (firstVertex < 0 || firstVertex >= size) {
        printf("Unexisted first vertex number.\n");

        return;
    }

    int* marked = (int*) malloc(size * sizeof(int));
    if (marked == NULL) {
        printf("Can`t allocate some dynamic memory for marked array.\n");

        return;
    }

    fillArrayIntByValue(marked, size, 0);

    Queue queue = createNewQueue(size);

    vertex = firstVertex;
    *(marked + firstVertex) = 1;

    puts("\nGraph full BFS demo.");
    printf("Matrix size: %dx%d; first vertex number: %d\n", size, size, firstVertex);

    do {
        depth = 0;

        for (j = 0; j < size; j++) {
            if (*(marked + j) == 0) {
                weight = *((matrix + vertex * size) + j);
                if (weight != -1) {
                    *(marked + j) = 1;

                    queue.enqueue(&queue, j);

                    // Визуализируем пути
                    printf("V(%d) --E(W:%d)-> V(%d)\n", vertex, weight, j);

                    depth++;
                }
            }
        }

        vertex = queue.dequeue(&queue);

        if (depth > 0) {
            maxDepth++;
        }
    } while (queue.size > 0);

    printf("\nMax graph tree height (depth): %d\n", maxDepth);
}
