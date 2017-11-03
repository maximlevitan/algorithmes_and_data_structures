#ifndef DYNAMIC_H_INCLUDED
#define DYNAMIC_H_INCLUDED

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
);

#endif // DYNAMIC_H_INCLUDED
