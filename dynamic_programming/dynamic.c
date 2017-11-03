/**
 * Dynamic programming algorithms
 *
 * @author Maxim Levitan <maximlevitan@gmail.com>
 */

#include <stdio.h>

#include "dynamic.h"

/**
 * W(a, b) = W(a, b − 1) + W(a − 1, b), a > 0, b > 0, map(a,b) = 1;
 * W(0, b) = 1, map(a,b) = 0;
 * W(a, 0) = 1, map(a,b) = 0;
 */
void countRoutsOfKingWithBarriers(
  int* result2dArray,
  int* barriers2dMap,
  int rowCount,
  int colCount
) {
    int j, i, deltaIdx;

    for (j = 0; j < colCount; j++) {
        *(result2dArray + j) = *(barriers2dMap + j) ? 1 : 0;
    }

    for(i = 1; i < rowCount; i++) {
        deltaIdx = i * colCount;
        *(result2dArray + deltaIdx) = *(barriers2dMap + deltaIdx) ? 1 : 0;

        for (j = 1; j < colCount; j++) {

            *(result2dArray + deltaIdx + j) = *(barriers2dMap + deltaIdx + j)
                ? (*(result2dArray + deltaIdx + j - 1) + *(result2dArray + deltaIdx - colCount + j))
                : 0;
        }
    }
}
