#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stddef.h>
#include <math.h>

/**
 * @brief Sorts an array of doubles in ascending order.
 * 
 * This function takes an array of doubles and sorts it in ascending order using the merge sort algorithm.
 * 
 * @param arr The array of doubles to be sorted.
 * @param length The length of the array.
 * 
 * @return A pointer to the sorted array of doubles.
 * 
 * @note It is the caller's responsibility to free the memory allocated for the array.
*/

static inline double *sort(const double *arr, size_t length)
{
  if (length == 0)
    return NULL;

  double *buffer1 = (double *)malloc(sizeof(*buffer1) * length),
         *buffer2 = (double *)malloc(sizeof(*buffer2) * length),
         *src, *target, *left, *right, *result, *unused;
  size_t i, j, k, half, targetIndex, leftIndex, rightIndex, log2_length, pow2_i;
  log2_length = (size_t)ceil(log2((double)length));

  for (i = 0; i < length; i++)
    buffer1[i] = arr[i];
  for (i = 1; i <= log2_length; i++)
  {
    src = i % 2 ? buffer1 : buffer2,
    target = !(i % 2) ? buffer1 : buffer2;
    targetIndex = 0;
    pow2_i = (size_t)pow(2, (double)i);
    half = pow2_i / 2;
    for (j = 0; j < length; j += pow2_i)
    {
      left = (double *)(src + j);
      right = (double *)(left + half);
      leftIndex = rightIndex = 0;
      for (k = 0; k < pow2_i && targetIndex < length; k++)
        if (leftIndex >= half)
          target[targetIndex++] = right[rightIndex++];
        else if (rightIndex >= half || j + half + rightIndex >= length)
          target[targetIndex++] = left[leftIndex++];
        else
          target[targetIndex++] = left[leftIndex] < right[rightIndex] ? left[leftIndex++] : right[rightIndex++];
    }
  }

  result = log2_length % 2 ? buffer2 : buffer1;
  unused = log2_length % 2 ? buffer1 : buffer2;

  free(unused);

  return result;
}

#endif /* SORT_H */
