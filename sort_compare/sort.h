#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

void swapInt(int* a, int* b);

void bubbleSortInt(int* input, int size, int* opCounter);

void boostedBubbleSortInt(int* input, int size, int* opCounter);

void shakerSortInt(int* input, int size, int* opCounter);

void shakerSortInt(int* input, int size, int* opCounter);

void simpleCountingSortInt(int* input, int size, int maxValue, int* opCounter);

/**
 * Quick Sort algorithm
 *
 * Fastest algorithm with complexity: O(n * log n), and O(n**2) in bed variant
 * But have big problem on big N: make N-level recursion (may be memory limit problem).
 */
void quickSortInt(int* input, int first, int last, int* opCounter);

/**
 * Merge Sort algorithm (recursion version)
 */
void recursionMergeSortInt(int* input, int left, int right, int* opCounter);

#endif // SORT_H_INCLUDED
