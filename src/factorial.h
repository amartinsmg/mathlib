#ifndef FACTORIAL_H
#define FACTORIAL_H

#include <errno.h>
#include <math.h>

/**
 * @brief Calculate the factorial of a number.
 *
 * @param num The number for which factorial is to be calculated.
 *
 * @return The factorial of the number.
 *
 * @note This function is suitable for numbers up to 20.
 * For larger values, use factoriallf(), which returns a double-precision
 * floating-point approximation in exponential form.
 */

static inline long long factorial(int num)
{
  if (num < 0 || num > 20)
  {
    errno = ERANGE;
    return 0;
  }

  long long result = 1;
  int i;
  for (i = 1; i <= num; i++)
    result *= i;
  return result;
}

/**
 * @brief Calculate the factorial of a number using double precision.
 *
 * @param num The number for which factorial is to be calculated.
 *
 * @return The factorial of the number.
 */

static inline double factoriallf(int num)
{
  if (num < 0)
    return NAN;
  double result = 1;
  int i;
  for (i = 1; i <= num; i++)
    result *= i;
  return result;
}

#endif /* FACTORIAL_H */
