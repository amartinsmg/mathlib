#ifndef ARMSTRONG_NUMBERS_H
#define ARMSTRONG_NUMBERS_H

#include <stdbool.h>
#include <math.h>

/**
 * @brief Check if a number is an Armstrong number.
 * 
 * @param num The number to be checked.
 * 
 * @return True if the number is an Armstrong number, false otherwise.
*/

static inline bool isArmstrong(long long num)
{
  int i,
      k = floor(log10(num) + 1);
  long long n = num,
            sum = 0;
  for (i = 0; i < k; i++)
  {
    sum += pow((n % 10), k);
    n /= 10;
  }
  if (sum == num)
    return true;
  return false;
}

#endif /* ARMSTRONG_NUMBERS_H */
