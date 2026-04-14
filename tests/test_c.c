#include "mathlib.h"
#include <stdio.h>
#include <stdlib.h>

#define SIZE_OF_ARR 8

#define ASSERT_TRUE(condition)                   \
  if (!(condition))                              \
  {                                              \
    printf("FAIL: %s:%d\n", __FILE__, __LINE__); \
    return EXIT_FAILURE;                         \
  }

int main()
{
  double mode,
      arr[SIZE_OF_ARR] = {2, 4, 6, 7, 5, 3, 2, 1};
  Vector v = math_mode(arr, SIZE_OF_ARR);
  size_t n_of_modes = v.length;
  mode = *(double *)v.data;
  vector_free(&v);

  ASSERT_TRUE(math_mean(arr, SIZE_OF_ARR) == 3.75);
  ASSERT_TRUE(n_of_modes == 1);
  ASSERT_TRUE(mode == 2);
  ASSERT_TRUE(math_gcd(12, 42) == 6);

  printf("Sanity test passed!\n\n");

  return EXIT_SUCCESS;
}
