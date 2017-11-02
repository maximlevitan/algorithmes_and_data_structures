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
void countRoutsOfKingWithBarriers(int* resultData, int* barriersMap, int rowCount, int colCount)
{
    int j, i, deltaIdx;

    for (j = 0; j < colCount; j++) {
        *(resultData + j) = *(barriersMap + j) ? 1 : 0;
    }

    for(i = 1; i < rowCount; i++) {
        deltaIdx = i * rowCount;
        *(resultData + deltaIdx)  = *(barriersMap + deltaIdx) ? 1 : 0;

        for (j = 1; j < colCount; j++) {
            deltaIdx += j;

            *(resultData + deltaIdx) = *(barriersMap + deltaIdx) ? (*(resultData + deltaIdx - 1) + *(resultData + deltaIdx - rowCount)) : 0;
        }
    }
}
