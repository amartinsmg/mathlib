#ifndef STATISTICS_H
#define STATISTICS_H

#include <stddef.h>
#include <math.h>
#include "basic_operations.h"
#include "percentage.h"
#include "sort.h"

/**
 * @brief Calculate the arithmetic mean of an array of values.
 *
 * @param arr The array of values.
 * @param length The length of the array.
 *
 * @return The calculated mean.
 */

static inline double mean(const double *arr, size_t length)
{
  if (length == 0)
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

static inline double weightedMean(const ValueWeight *values_weights, size_t length)
{
  if (length == 0)
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
 * @param trimmedMeanPercentage The percentage of elements to be trimmed from both ends.
 *
 * @return The trimmed mean of the arr.
 */

static inline double trimmedMean(const double *arr, size_t length, double trimmedMeanPercentage)
{
  if (length == 0)
    return NAN;
  size_t nElementsToTrim = (size_t)round(nPercentOfX(length, trimmedMeanPercentage));
  if (2 * nElementsToTrim >= length)
    return NAN;
  double result, *sortedArr = sort(arr, length);
  arr += nElementsToTrim;
  length -= 2 * nElementsToTrim;
  result = mean(arr, length);
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

static inline double geometricMean(const double *arr, size_t length)
{
  if (length == 0)
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
  result = nthRoot(product, length);
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

static inline double harmonicMean(const double *arr, size_t length)
{
  if (length == 0)
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

static inline double median(const double *arr, size_t length)
{
  if (length <= 0)
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

static inline double *mode(const double *arr, size_t length, size_t *ptrNOfModes)
{
  if (length == 0)
  {
    *ptrNOfModes = 0;
    return NULL;
  }
  double *result = NULL,
         *sortedArr = sort(arr, length);
  Freq *frequencies = malloc(sizeof(*frequencies) * length);
  size_t i,
      minFreq = __UINT32_MAX__,
      maxFreq = 0,
      resultLenght = 0,
      freq_len = 0;

  frequencies[freq_len++].value = sortedArr[0];
  frequencies[freq_len++].value = 1;
  for (i = 0; i < length; i++)
    if (sortedArr[i] == frequencies[freq_len - 1].value)
      frequencies[freq_len - 1].frequency++;
    else
    {
      frequencies[freq_len].value = sortedArr[i];
      frequencies[freq_len++].frequency++;
    }
  for (i = 0; i < freq_len; i++)
  {
    minFreq = frequencies[i].frequency < minFreq ? frequencies[i].frequency : minFreq;
    maxFreq = frequencies[i].frequency > maxFreq ? frequencies[i].frequency : maxFreq;
  }
  *ptrNOfModes = 0;
  if (minFreq < maxFreq)
    for (i = 0; i < freq_len; i++)
      if (frequencies[i].frequency == maxFreq)
      {
        result = (double *)realloc(result, sizeof(*result) * ++(*ptrNOfModes));
        result[resultLenght++] = frequencies[i].value;
      }

  free(frequencies);
  free(sortedArr);

  return result;
}

/**
 * @brief Find the minimum value in an array of values.
 *
 * @param arr The array of values.
 * @param length The length of the array.
 *
 * @return The minimum value.
 */

static inline double min(const double *arr, size_t length)
{
  if (length == 0)
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

static inline double max(const double *arr, size_t length)
{
  if (length == 0)
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

static inline double range(const double *arr, size_t length)
{
  if (length == 0)
    return NAN;
  double minValue = min(arr, length),
         maxValue = max(arr, length),
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

static inline double midrange(const double *arr, size_t length)
{
  double result = range(arr, length) / 2;
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

static inline double variance(const double *arr, size_t length)
{
  if (length == 0)
    return NAN;
  double mu = mean(arr, length),
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

static inline double standardDeviation(const double *arr, size_t length)
{
  if (length == 0)
    return NAN;
  double result = sqrt(variance(arr, length));
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

static inline double sampleVariance(const double *arr, size_t length)
{
  if (length <= 1)
    return NAN;
  double mu = mean(arr, length),
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

static inline double sampleStandardDeviation(const double *arr, size_t length)
{
  if (length <= 1)
    return NAN;
  double result = sqrt(sampleVariance(arr, length));
  return result;
}

#endif /* STATISTICS_H */
