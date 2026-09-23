#include "internal/mathlib_c.h"
#include "utils/sort.h"
#include "utils/vector.h"
#include <stddef.h>
#include <stdlib.h>

double mean(const double *arr, size_t length) {
  if (length == 0 || arr == NULL)
    return NAN;

  double result;
  double sum = 0;
  size_t i;

  for (i = 0; i < length; i++)
    sum += (arr[i] - sum) / (double)(i + 1);

  result = sum;
  return result;
}

double trimmedMean(const double *arr, size_t length, double percentage) {
  if (length == 0 || arr == NULL)
    return NAN;

  size_t n_el_to_trim = (size_t)round(nPercentOfX(length, percentage));

  if (2 * n_el_to_trim >= length)
    return NAN;

  double result;
  double *sortedArr = sort(arr, length);
  arr += n_el_to_trim;
  length -= 2 * n_el_to_trim;

  result = mean(arr, length);
  free(sortedArr);

  return result;
}

double geometricMean(const double *arr, size_t length) {
  if (length == 0 || arr == NULL)
    return NAN;

  double result;
  double product = 1;
  size_t i;

  for (i = 0; i < length; i++) {
    if (arr[i] <= 0)
      return NAN;
    product *= nthRoot(arr[i], length);
  }

  result = product;
  return result;
}

double harmonicMean(const double *arr, size_t length) {
  if (length == 0 || arr == NULL)
    return NAN;

  double result;
  double sum = 0;
  size_t i;

  for (i = 0; i < length; i++) {
    if (arr[i] <= 0)
      return NAN;
    sum += 1 / arr[i];
  }

  result = length / sum;
  return result;
}

double median(const double *arr, size_t length) {
  if (length == 0 || arr == NULL)
    return NAN;

  double result;
  double *sorted_arr = sort(arr, length);

  if (length % 2 != 0)
    result = sorted_arr[length / 2];
  else
    result = (sorted_arr[(length / 2) - 1] + sorted_arr[length / 2]) / 2;
  free(sorted_arr);

  return result;
}

/**
 * @brief Structure representing a value and its frequency.
 */

typedef struct {
  double value;
  size_t frequency;
} freq_t;

static Vector get_frequencies(const double *arr, size_t length) {
  double *sorted_arr = sort(arr, length);
  Vector frequencies = vector_init(sizeof(freq_t));

  if (sorted_arr != NULL) {
    size_t i;

    freq_t tmp = {.value = sorted_arr[0], .frequency = 1};

    for (i = 1; i < length; i++) {
      if (sorted_arr[i] != tmp.value || i == length - 1) {
        if (vector_append(&frequencies, &tmp)) {
          vector_free(&frequencies);
          break;
        }
        tmp.value = sorted_arr[i];
        tmp.frequency = 1;
      } else {
        tmp.frequency += 1;
      }
    }
  }

  if (sorted_arr != NULL)
    free(sorted_arr);

  return frequencies;
}

double *mode(const double *arr, size_t length, size_t *size) {

  if (length == 0 || arr == NULL)
    return NULL;

  Vector modes = vector_init(sizeof(double));

  double *result = NULL;

  Vector frequencies_vector = get_frequencies(arr, length);
  freq_t *frequencies = (freq_t *)vector_get_values(&frequencies_vector);

  if (frequencies != NULL) {
    size_t i;
    size_t min_freq = __UINT32_MAX__;
    size_t max_freq = 0;
    int status = 0;

    for (i = 0; i < frequencies_vector.length; i++) {
      size_t tmp_freq = frequencies[i].frequency;
      min_freq = tmp_freq < min_freq ? tmp_freq : min_freq;
      max_freq = tmp_freq > max_freq ? tmp_freq : max_freq;
    }

    if (max_freq > min_freq)
      for (i = 0; i < frequencies_vector.length; i++) {
        freq_t tmp = frequencies[i];
        if (tmp.frequency == max_freq)
          if (vector_append(&modes, &tmp.value) != 0) {
            status = -1;
            break;
          }
      }

    if (status == 0) {
      result = (double *)vector_get_values(&modes);
      *size = modes.length;
    } else {
      *size = 0;
    }

    free(frequencies);
  }

  vector_free(&frequencies_vector);

  vector_free(&modes);

  return result;
}

double min(const double *arr, size_t length) {
  if (length == 0 || arr == NULL)
    return NAN;
  double result = __DBL_MAX__;
  size_t i;
  for (i = 0; i < length; i++)
    result = arr[i] < result ? arr[i] : result;
  return result;
}

double max(const double *arr, size_t length) {
  if (length == 0 || arr == NULL)
    return NAN;

  double result = -__DBL_MAX__;
  size_t i;

  for (i = 0; i < length; i++)
    result = arr[i] > result ? arr[i] : result;

  return result;
}

double range(const double *arr, size_t length) {
  if (length == 0 || arr == NULL)
    return NAN;

  double minValue = min(arr, length);
  double maxValue = max(arr, length);
  double result = maxValue - minValue;
  return result;
}

double midrange(const double *arr, size_t length) {
  if (length == 0 || arr == NULL)
    return NAN;

  double minValue = min(arr, length);
  double maxValue = max(arr, length);
  double result = (maxValue + minValue) / 2;
  return result;
}

double variance(const double *arr, size_t length) {
  if (length == 0 || arr == NULL)
    return NAN;

  double mu = mean(arr, length);
  double sum = 0;
  double result;
  size_t i;

  for (i = 0; i < length; i++)
    sum += pow((arr[i] - mu), 2);

  result = sum / length;
  return result;
}

double stdDev(const double *arr, size_t length) {
  if (length == 0 || arr == NULL)
    return NAN;

  double result = sqrt(variance(arr, length));
  return result;
}

double sampleVariance(const double *arr, size_t length) {
  if (length <= 1)
    return NAN;

  double mu = mean(arr, length);
  double sum = 0;
  double result;
  size_t i;

  for (i = 0; i < length; i++)
    sum += pow((arr[i] - mu), 2);

  result = sum / (length - 1);
  return result;
}

double sampleStdDev(const double *arr, size_t length) {
  if (length <= 1)
    return NAN;

  double result = sqrt(sampleVariance(arr, length));
  return result;
}
