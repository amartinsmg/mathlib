#ifndef PRIME_FACTORIZATION_H
#define PRIME_FACTORIZATION_H

#include <stdlib.h>
#include "vector.h"

/**
 * @brief Calculate the prime factors of a given number.
 *
 * @param num The number to calculate prime factors for.
 *
 * @return An array of prime factors.
 *
 * @note It is the caller's responsibility to free the memory allocated for the array.
 */

static inline Vector math_primeFactors(long long num)
{
  long long i;
  Vector factors = vector_init(sizeof(long long));
  while (num > 1)
    for (i = 2; i <= num; i++)
      if (!(num % i))
      {
        vector_append(&factors, &i);
        num /= i;
        break;
      }
  return factors;
}

#endif /* PRIME_FACTORIZATION_H */
