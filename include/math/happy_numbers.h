#ifndef HAPPY_NUMBERS_H
#define HAPPY_NUMBERS_H

#include <stdbool.h>
#include "set.h"

/**
 * @brief Checks whether the given number is a happy number.
 *
 * @param num The number to be checked.
 *
 * @return True if the number is a happy number, false otherwise.
 */

static inline bool math_isHappy(long long num)
{
  long long sum;
  Set numSet = {0};
  int i, remainder;
  set_add_value(&numSet, num);
  while (true)
  {
    sum = 0;
    while (num > 0)
    {
      remainder = num % 10;
      num /= 10;
      sum += remainder * remainder;
    }
    if (sum == 1)
    {
      set_free(&numSet);
      return true;
    }
    if (set_contains(&numSet, sum))
    {
      set_free(&numSet);
      return false;
    }
    set_add_value(&numSet, sum);
    num = sum;
  }
}

#endif /* HAPPY_NUMBERS_H */
