#include "utils/sort.h"
#include <math.h>
#include <stddef.h>
#include <stdlib.h>

static void mergesort_pipeline(double *src, double *target, size_t length,
                               size_t index) {
  size_t tgt_index = 0;
  size_t pow_2_i = 1 << index;
  size_t half = pow_2_i / 2;
  for (size_t j = 0; j < length; j += pow_2_i) {
    double *left = (double *)(src + j);
    double *right = (double *)(left + half);
    size_t l_index = 0;
    size_t r_index = 0;
    for (size_t k = 0; k < pow_2_i && tgt_index < length; k++)
      if (l_index >= half)
        target[tgt_index++] = right[r_index++];
      else if (r_index >= half || j + half + r_index >= length)
        target[tgt_index++] = left[l_index++];
      else
        target[tgt_index++] =
            left[l_index] < right[r_index] ? left[l_index++] : right[r_index++];
  }
}

double *sort(const double *arr, size_t length) {
  if (length == 0)
    return NULL;

  double *buffer_1 = (double *)malloc(sizeof(*buffer_1) * length);
  double *buffer_2 = (double *)malloc(sizeof(*buffer_2) * length);

  if (buffer_1 == NULL || buffer_2 == NULL) {
    if (buffer_1)
      free(buffer_1);
    if (buffer_2)
      free(buffer_2);
    return NULL;
  }

  double *result;
  double *unused;
  size_t log2_length = (size_t)ceil(log2((double)length));

  for (size_t i = 0; i < length; i++)
    buffer_1[i] = arr[i];

  for (size_t i = 1; i <= log2_length; i++) {
    if (i % 2)
      mergesort_pipeline(buffer_1, buffer_2, length, i);
    else
      mergesort_pipeline(buffer_2, buffer_1, length, i);
  }

  result = log2_length % 2 ? buffer_2 : buffer_1;
  unused = log2_length % 2 ? buffer_1 : buffer_2;

  free(unused);

  return result;
}