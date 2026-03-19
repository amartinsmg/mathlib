#ifndef LCM_H
#define LCM_H

#include <errno.h>
#include <stdlib.h>
#include "gcd.h"

/**
 * @brief Calculate the least common multiple (LCM) of two integers.
 *
 * @param x The first integer.
 * @param y The second integer.
 *
 * @return The LCM of 'x' and 'y'.
 */

static inline long long math_lcm(int x, int y)
{
  if (x == 0 || y == 0)
    return 0;
  long long product = (long long) x * (long long) y;
  long long result = llabs(product / math_gcd(x, y));
  return result;
}

#endif /* LCM_H */
