#ifndef COMBINATORICS_H
#define COMBINATORICS_H

#include "factorial.h"
#include <errno.h>
#include <stdio.h>
#include <math.h>

/**
 * @brief Calculate the cycle permutation of a number.
 *
 * @param num The number for which cycle permutation is to be calculated.
 *
 * @return The permutation of the number.
 *
 * @note This function is suitable for numbers up to 20.
 * For larger values, use math_permutationlf(), which returns a double-precision
 * floating-point approximation in exponential form.
 */

static inline unsigned long long math_permutation(unsigned num)
{
  unsigned long long result;
  result = math_factorial(num);
  return result;
}

/**
 * @brief Calculate the cycle permutation of a number.
 *
 * @param num The number for which cycle permutation is to be calculated.
 *
 * @return The cycle permutation of the number.
 *
 * @note This function is suitable for numbers up to 20.
 * For larger values, use math_cyclePermutaionlf(), which returns a double-precision
 * floating-point approximation in exponential form.
 */

static inline unsigned long long math_cyclePermutation(unsigned num)
{
  if (num <= 1)
    return 1;
  unsigned long long result;
  result = math_factorial(num - 1);
  return result;
}

/**
 * @brief Calculate the arrangement of selecting 'selected' items from 'total' items.
 *
 * @param total The total number of items.
 * @param selected The number of items to be selected.
 *
 * @return The arrangement of selecting 'selected' items from 'total' items.
 *
 * @note This function is suitable for numbers up to 20.
 * For larger values, use math_arrangementlf(), which returns a double-precision
 * floating-point approximation in exponential form.
 */

static inline unsigned long long math_arrangement(unsigned total, unsigned selected)
{
  if (total == 0 || selected > total)
  {
    errno = EDOM;
    perror("Error calculating arrangement");
    return 0;
  }
  unsigned long long result;
  result = math_factorial(total) / math_factorial(total - selected);
  return result;
}

/**
 * @brief Calculate the combination of selecting 'selected' items from 'total' items.
 *
 * @param total The total number of items.
 * @param selected The number of items to be selected.
 *
 * @return The combination of selecting 'selected' items from 'total' items.
 *
 * @note This function is suitable for numbers up to 20.
 * For larger values, use math_combinationlf(), which returns a double-precision
 * floating-point approximation in exponential form.
 */

static inline unsigned long long math_combination(unsigned total, unsigned selected)
{
  if (total == 0 || selected > total)
  {
    errno = EDOM;
    perror("Error calculating combination");
    return 0;
  }
  unsigned long long result;
  result = math_factorial(total) / (math_factorial(selected) * math_factorial(total - selected));
  return result;
}

/**
 * @brief Calculate the permutation of a number using double precision.
 *
 * @param num The number for which permutation is to be calculated.
 *
 * @return The permutation of the number (double precision).
 */

static inline double math_permutationlf(unsigned num)
{
  double result;
  result = math_factoriallf(num);
  return result;
}

/**
 * @brief Calculate the cycle permutation of a number using double precision.
 *
 * @param num The number for which permutation is to be calculated.
 *
 * @return The cycle permutation of the number (double precision).
 */

static inline double math_cyclePermutationlf(unsigned num)
{
  if (num <= 1)
    return 1;
  double result;
  result = math_factoriallf(num - 1);
  return result;
}

/**
 * @brief Calculate the arrangement of selecting 'selected' items from 'total' items using double precision.
 *
 * @param total The total number of items.
 * @param selected The number of items to be selected.
 *
 * @return The arrangement of selecting 'selected' items from 'total' items (double precision).
 */

static inline double math_arrangementlf(unsigned total, unsigned selected)
{
  if (total == 0 || selected > total)
    return NAN;
  double result;
  result = math_factoriallf(total) / math_factoriallf(total - selected);
  return result;
}

/**
 * @brief Calculate the combination of selecting 'selected' items from 'total' items using double precision.
 *
 * @param total The total number of items.
 * @param selected The number of items to be selected.
 *
 * @return The combination of selecting 'selected' items from 'total' items (double precision).
 */

static inline double math_combinationlf(unsigned total, unsigned selected)
{
  if (total == 0 || selected > total)
    return NAN;
  double result;
  result = math_factoriallf(total) / (math_factoriallf(selected) * math_factoriallf(total - selected));
  return result;
}

#endif /* COMBINATORICS_H */
