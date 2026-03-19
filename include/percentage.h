#ifndef PERCENTAGE_H
#define PERCENTAGE_H

/**
 * @brief Calculate n percent of x.
 *
 * @param x The value.
 * @param n The percentage.
 *
 * @return The calculated result.
 */

static inline double math_nPercentOfX(double x, double n)
{
  if (n == 0)
    return 0;
  double result = x / 100 * n;
  return result;
}

/**
 * @brief Calculate what percentage n is of x.
 *
 * @param x The value.
 * @param n The value to calculate the percentage for.
 *
 * @return The calculated percentage.
 */

static inline double math_nIsWhatPercentOfX(double x, double n)
{
  if (x == 0)
    return 0;
  double result = n / x * 100;
  return result;
}

#endif /* PERCENTAGE_H */
