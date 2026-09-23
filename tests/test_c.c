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
  double arr[SIZE_OF_ARR] = {2, 4, 6, 7, 5, 3, 2, 1};
  size_t n_of_modes;
  double* mode_ptr = mode(arr, SIZE_OF_ARR, &n_of_modes);
  double mode_result = mode_ptr[0];

  freeArray(mode_ptr);

  ASSERT_TRUE(mean(arr, SIZE_OF_ARR) - 3.75 < 1e-15);
  ASSERT_TRUE(n_of_modes == 1);
  ASSERT_TRUE(mode_result == 2);
  ASSERT_TRUE(gcd(12, 42) == 6);

  printf("Sanity test passed!\n\n");

  return EXIT_SUCCESS;
}
