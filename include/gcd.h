#ifndef GCD_H
#define GCD_H

#include <math.h>

/**
 * @brief Calculate the greatest common divisor (GCD) of two integers.
 * 
 * @param x The first integer.
 * @param y The second integer.
 * @return The GCD of 'x' and 'y'.
 * 
 * @pre x and y cannot both be 0.
*/

static inline int math_gcd(int x, int y)
{
  int result, remainder;
  if (x == 0)
    return abs(y);
  if (y == 0)
    return abs(x);
  remainder = x % y;
  while (remainder)
  {
    x = y;
    y = remainder;
    remainder = x % y;
  }
  result = abs(y);
  return result;
}

#endif /* GCD_H */
