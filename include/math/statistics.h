#ifndef STATISTICS_H
#define STATISTICS_H

#include <stddef.h>
#include <math.h>
#include "basic_operations.h"
#include "percentage.h"
#include "sort.h"
#include "vector.h"

/**
 * @brief Calculate the arithmetic mean of an array of values.
 *
 * @param arr The array of values.
 * @param length The length of the array.
 *
 * @return The calculated mean.
 */

static inline double math_mean(const double *arr, size_t length)
{
  if (length == 0 || arr == NULL)
    return NAN;
  double result,
      sum = 0;
  size_t i;
  for (i = 0; i < length; i++)
    sum += arr[i];
  result = sum / length;
  return result;
}

/**
 * @brief Structure representing a value and its weight.
 */

typedef struct
{
  double value;
  double weight;
} ValueWeight;

/**
 * @brief Calculate the weighted mean of a set of values.
 *
 * @param values_weights The array of value-weight pairs. Each pair is represented
  as a double array with two elements: [value, weight].
 * @param length The length of the values_weights array.
 *
 * @return The weighted mean of the arr.
*/

static inline double math_weightedMean(const ValueWeight *values_weights, size_t length)
{
  if (length == 0 || values_weights == NULL)
    return NAN;
  double result, value, weight,
      sum = 0,
      weightSum = 0;
  size_t i;
  for (i = 0; i < length; i++)
  {
    value = values_weights[i].value;
    weight = values_weights[i].weight;
    if (weight <= 0)
      return NAN;
    sum += value * weight;
    weightSum += weight;
  }
  result = sum / weightSum;
  return result;
}

/**
 * @brief Calculate the trimmed mean of an array of values.
 *
 * @param arr The array of values.
 * @param length The length of the arr array.
 * @param percentage The percentage of elements to be trimmed from both ends.
 *
 * @return The trimmed mean of the arr.
 */

static inline double math_trimmedMean(const double *arr, size_t length, double percentage)
{
  if (length == 0 || arr == NULL)
    return NAN;
  size_t nElementsToTrim = (size_t)round(math_nPercentOfX(length, percentage));
  if (2 * nElementsToTrim >= length)
    return NAN;
  double result, *sortedArr = sort(arr, length);
  arr += nElementsToTrim;
  length -= 2 * nElementsToTrim;
  result = math_mean(arr, length);
  free(sortedArr);
  return result;
}

/**
 * @brief Calculate the geometric mean of an array of values.
 *
 * @param arr The array of values.
 * @param length The length of the array.
 *
 * @return The calculated geometric mean.
 */

static inline double math_geometricMean(const double *arr, size_t length)
{
  if (length == 0 || arr == NULL)
    return NAN;
  double result,
      product = 1;
  size_t i;
  for (i = 0; i < length; i++)
  {
    if (arr[i] <= 0)
      return NAN;
    product *= arr[i];
  }
  result = math_nthRoot(product, length);
  return result;
}

/**
 * @brief Calculate the harmonic mean of an array of values.
 *
 * @param arr The array of values.
 * @param length The length of the array.
 *
 * @return The calculated harmonic mean.
 */

static inline double math_harmonicMean(const double *arr, size_t length)
{
  if (length == 0 || arr == NULL)
    return NAN;
  double result,
      sum = 0;
  size_t i;
  for (i = 0; i < length; i++)
  {
    if (arr[i] <= 0)
      return NAN;
    sum += 1 / arr[i];
  }
  result = length / sum;
  return result;
}

/**
 * @brief Calculate the median of an array of values.
 *
 * @param arr The array of values.
 * @param length The length of the array.
 *
 * @return The calculated median.
 */

static inline double math_median(const double *arr, size_t length)
{
  if (length == 0 || arr == NULL)
    return NAN;
  double result,
      *sortedArr = sort(arr, length);
  if (length % 2)
    result = sortedArr[length / 2];
  else
    result = (sortedArr[length / 2 - 1] + sortedArr[length / 2]) / 2;
  free(sortedArr);
  return result;
}

/**
 * @brief Structure representing a value and its frequency.
 */

typedef struct
{
  double value;
  size_t frequency;
} Freq;

/**
 * @brief Calculate the mode(s) of an array of values.
 *
 * @param arr The array of values.
 * @param length The length of the array.
 * @param ptrNOfModes Pointer to store the number of modes found.
 *
 * @return An array containing the mode(s) of the input values.
 *
 * @note The number of modes is stored in ptrNOfModes.
 */

static inline Vector math_mode(const double *arr, size_t length)
{
  Vector modes = vector_init(sizeof(double));

  if (length == 0 || arr == NULL)
    return modes;

  double *sortedArr = sort(arr, length);
  Freq *frequencies = (Freq *)malloc(sizeof(*frequencies) * length);
  size_t i,
      minFreq = __UINT32_MAX__,
      maxFreq = 0,
      resultLenght = 0,
      freq_len = 0;

  frequencies[0].value = sortedArr[0];
  frequencies[0].frequency = 1;
  freq_len++;

  for (i = 1; i < length; i++)
    if (sortedArr[i] == frequencies[freq_len - 1].value)
      frequencies[freq_len - 1].frequency++;
    else
    {
      frequencies[freq_len].value = sortedArr[i];
      frequencies[freq_len++].frequency = 1;
    }
  free(sortedArr);

  for (i = 0; i < freq_len; i++)
  {
    minFreq = frequencies[i].frequency < minFreq ? frequencies[i].frequency : minFreq;
    maxFreq = frequencies[i].frequency > maxFreq ? frequencies[i].frequency : maxFreq;
  }

  if (maxFreq > minFreq)
    for (i = 0; i < freq_len; i++)
      if (frequencies[i].frequency == maxFreq)
        vector_append(&modes, &frequencies[i].value);

  free(frequencies);

  return modes;
}

/**
 * @brief Find the minimum value in an array of values.
 *
 * @param arr The array of values.
 * @param length The length of the array.
 *
 * @return The minimum value.
 */

static inline double math_min(const double *arr, size_t length)
{
  if (length == 0 || arr == NULL)
    return NAN;
  double result = __DBL_MAX__;
  size_t i;
  for (i = 0; i < length; i++)
    result = arr[i] < result ? arr[i] : result;
  return result;
}

/**
 * @brief Find the maximum value in an array of values.
 *
 * @param arr The array of values.
 * @param length The length of the array.
 *
 * @return The maximum value.
 */

static inline double math_max(const double *arr, size_t length)
{
  if (length == 0 || arr == NULL)
    return NAN;
  double result = -__DBL_MAX__;
  size_t i;
  for (i = 0; i < length; i++)
    result = arr[i] > result ? arr[i] : result;
  return result;
}

/**
 * @brief Calculate the range of an array of values.
 *
 * @param arr The array of values.
 * @param length The length of the array.
 *
 * @return The calculated range.
 */

static inline double math_range(const double *arr, size_t length)
{
  if (length == 0 || arr == NULL)
    return NAN;
  double minValue = math_min(arr, length),
         maxValue = math_max(arr, length),
         result = maxValue - minValue;
  return result;
}

/**
 * @brief Calculate the midrange of an array of values.
 *
 * @param arr The array of values.
 * @param length The length of the array.
 *
 * @return The calculated midrange.
 */

static inline double math_midrange(const double *arr, size_t length)
{
  double result = math_range(arr, length) / 2;
  return result;
}

/**
 * @brief Calculate the variance of an array of values.
 *
 * @param arr The array of values.
 * @param length The length of the array.
 *
 * @return The calculated variance.
 */

static inline double math_variance(const double *arr, size_t length)
{
  if (length == 0 || arr == NULL)
    return NAN;
  double mu = math_mean(arr, length),
         sum = 0,
         result;
  size_t i;
  for (i = 0; i < length; i++)
    sum += pow((arr[i] - mu), 2);
  result = sum / length;
  return result;
}

/**
 * @brief Calculate the standard deviation of an array of values.
 *
 * @param arr The array of values.
 * @param length The length of the array.
 *
 * @return The calculated standard deviation.
 */

static inline double math_stdDev(const double *arr, size_t length)
{
  if (length == 0 || arr == NULL)
    return NAN;
  double result = sqrt(math_variance(arr, length));
  return result;
}

/**
 * @brief Calculate the sample variance of an array of values.
 *
 * @param arr The array of values.
 * @param length The length of the array.
 *
 * @return The calculated sample variance.
 */

static inline double math_sampleVariance(const double *arr, size_t length)
{
  if (length <= 1)
    return NAN;
  double mu = math_mean(arr, length),
         sum = 0,
         result;
  size_t i;
  for (i = 0; i < length; i++)
    sum += pow((arr[i] - mu), 2);
  result = sum / (length - 1);
  return result;
}

/**
 * @brief Calculate the sample standard deviation of an array of values.
 *
 * @param arr The array of values.
 * @param length The length of the array.
 *
 * @return The calculated sample standard deviation.
 */

static inline double math_sampleStdDev(const double *arr, size_t length)
{
  if (length <= 1)
    return NAN;
  double result = sqrt(math_sampleVariance(arr, length));
  return result;
}

#endif /* STATISTICS_H */
