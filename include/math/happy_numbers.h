#ifndef HAPPY_NUMBERS_H
#define HAPPY_NUMBERS_H

#include "set.h"
#include <stdbool.h>

/**
 * @brief Checks whether the given number is a happy number.
 *
 * @param num The number to be checked.
 *
 * @return True if the number is a happy number, false otherwise.
 */

static inline bool math_is_happy(long long num)
{
  long long sum, remainder;
  Set num_set = {0};
  set_add_value(&num_set, num);
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
      set_free(&num_set);
      return true;
    }
    if (set_contains(&num_set, sum))
    {
      set_free(&num_set);
      return false;
    }
    set_add_value(&num_set, sum);
    num = sum;
  }
}

#endif /* HAPPY_NUMBERS_H */
