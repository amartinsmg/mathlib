#ifndef PRIME_FACTORIZATION_H
#define PRIME_FACTORIZATION_H

#include <stdlib.h>

/**
 * @brief Calculate the prime factors of a given number.
 *
 * @param num The number to calculate prime factors for.
 *
 * @return An array of prime factors.
 *
 * @note It is the caller's responsibility to free the memory allocated for the array.
 */

static inline long long *math_primeFactors(long long num)
{
  if (num <= 1)
    return NULL;
  long long i,
      *factors = (long long *)calloc(64, sizeof(*factors)),
      length = 0;
  while (num > 1)
    for (i = 2; i <= num; i++)
      if (!(num % i))
      {
        factors[length++] = i;
        num /= i;
        break;
      }
  return factors;
}

#endif /* PRIME_FACTORIZATION_H */
