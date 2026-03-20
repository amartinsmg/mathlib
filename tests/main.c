#include <stdio.h>
#include <stdlib.h>
#include <mathlib.h>
#include "include/test.h"

#define SIZE_OF_ARR 8
/**
 * @brief Main function to test mathematical algorithms.
 * This is the main function used to test different mathematical algorithms
 * by comparing the results with pre-calculated values. It serves as a testing
 * ground for verifying the correctness of the algorithms.
 *
 * @return An integer representing the exit status of the program.
 */

int main()
{
  double mode,
      arr[SIZE_OF_ARR] = {2, 4, 6, 7, 5, 3, 2, 1};
  Vector v = math_mode(arr, SIZE_OF_ARR);
  size_t nOfModes = v.length;
  mode = *(double *)v.data;
  vector_free(&v);

  ASSERT_TRUE(math_mean(arr, SIZE_OF_ARR) == 3.75);
  ASSERT_TRUE(nOfModes == 1);
  ASSERT_TRUE(mode == 2);
  ASSERT_TRUE(math_gcd(12, 42) == 6);

  printf("Sanity test passed!\n");

  return EXIT_SUCCESS;
}
