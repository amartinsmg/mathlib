#ifndef BASIC_OPERATIONS_H
#define BASIC_OPERATIONS_H

#include <math.h>

/**
 * @brief Calculate the logarithm of a number with a given base.
 *
 * @param num The number for which the logarithm will be calculated.
 * @param base The base of the logarithm.
 *
 * @return The logarithm of the number with the given base.
 */

static inline double math_logarithm(double num, double base)
{
  if (num <= 0 || base <= 0 || base == 1)
    return NAN;
  double result = log(num) / log(base);
  return result;
}

/**
 * @brief Calculate the nth root of a radicand.
 *
 * @param radicand The number to take the nth root of.
 * @param degree The degree of the root.
 *
 * @return The nth root of the radicand.
 */

static inline double math_nth_root(double radicand, double degree)
{
  if (degree == 0)
    return NAN;
  double result = pow(radicand, (1 / degree));
  return result;
}

/**
 * @brief Round a number to a specified number of decimal places.
 *
 * @param num The number to be rounded.
 * @param decimal_places The number of decimal places to round to.
 *
 * @return The rounded number.
 */

static inline double math_round_to(double num, unsigned decimal_places)
{
  double result, base_10 = pow(10, decimal_places);
  result = round(num * base_10) / base_10;
  return result;
}

#endif /* BASIC_OPERATIONS_H */
