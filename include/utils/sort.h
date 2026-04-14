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

  double *buffer_1 = (double *)malloc(sizeof(*buffer_1) * length),
         *buffer_2 = (double *)malloc(sizeof(*buffer_2) * length),
         *src, *target, *left, *right, *result, *unused;
  size_t i, j, k, half, target_i, left_i, right_i, log2_length, pow_2_i;
  log2_length = (size_t)ceil(log2((double)length));

  for (i = 0; i < length; i++)
    buffer_1[i] = arr[i];
  for (i = 1; i <= log2_length; i++)
  {
    src = i % 2 ? buffer_1 : buffer_2,
    target = !(i % 2) ? buffer_1 : buffer_2;
    target_i = 0;
    pow_2_i = 1 << i;
    half = pow_2_i / 2;
    for (j = 0; j < length; j += pow_2_i)
    {
      left = (double *)(src + j);
      right = (double *)(left + half);
      left_i = right_i = 0;
      for (k = 0; k < pow_2_i && target_i < length; k++)
        if (left_i >= half)
          target[target_i++] = right[right_i++];
        else if (right_i >= half || j + half + right_i >= length)
          target[target_i++] = left[left_i++];
        else
          target[target_i++] = left[left_i] < right[right_i]
                                   ? left[left_i++]
                                   : right[right_i++];
    }
  }

  result = log2_length % 2 ? buffer_2 : buffer_1;
  unused = log2_length % 2 ? buffer_1 : buffer_2;

  free(unused);

  return result;
}

#endif /* SORT_H */
