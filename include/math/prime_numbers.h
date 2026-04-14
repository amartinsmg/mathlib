#ifndef PRIME_NUMBERS_H
#define PRIME_NUMBERS_H

#include <stdbool.h>

/**
  @brief Checks whether the given number is a prime number.
  @param num The number to be checked.
  @return True if the number is a prime number, false otherwise.
*/

static inline bool math_is_prime(long long num)
{
  long long i;
  for (i = 2; num % i && i <= num; i++)
    if (i * i > num)
      return true;
  if (i == num)
    return true;
  return false;
}

#endif /* PRIME_NUMBERS_H */
