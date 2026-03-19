#ifndef GROWTH_H
#define GROWTH_H

#include <math.h>
#include "basic_operations.h"

/**
 * @brief Calculate the value after simple growth.
 *
 * @param initial The initial value.
 * @param rate The growth rate.
 * @param interval The time interval.
 *
 * @return The calculated value after simple growth.
 */

static inline double math_simpleGrowth(double initial, double rate, double interval)
{
  if (interval < 0)
    return NAN;
  double result;
  result = initial * (1 + rate * interval);
  return result;
}

/**
 * @brief Calculate the simple growth rate.
 *
 * @param initial The initial value.
 * @param final The final value.
 * @param interval The time interval.
 *
 * @return The calculated simple growth rate.
 */

static inline double math_simpleGrowthRate(double initial, double final, double interval)
{
  if (initial == 0 || interval <= 0)
    return NAN;
  double result;
  result = (final / initial - 1) / interval;
  return result;
}

/**
 * @brief Calculate the value after compounded growth.
 *
 * @param initial The initial value.
 * @param rate The growth rate.
 * @param interval The time interval.
 *
 * @return The calculated value after compounded growth.
 */

static inline double math_compoundedGrowth(double initial, double rate, double interval)
{
  if (interval < 0)
    return NAN;
  double result;
  result = initial * pow((1 + rate), interval);
  return result;
}

/**
 * @brief Calculate the compounded growth rate.
 * 
 * @param initial The initial value.
 * @param final The final value.
 * @param interval The time interval.
 * 
 * @return The calculated compounded growth rate.
 */

static inline double math_compoundedGrowthRate(double initial, double final, double interval)
{
  if (initial == 0 || interval <= 0)
    return NAN;
  double result;
  result = math_nthRoot((final / initial), interval) - 1;
  return result;
}

#endif /* GROWTH_H */
