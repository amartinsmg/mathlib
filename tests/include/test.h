#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Execute a test and report its result.
 *
 * This function prints the test number and whether it passed or failed.
 * If the condition is true, the test is considered passed and the function
 * returns 0. Otherwise, the test is considered failed, a cleanup message
 * is printed, and the function returns -1.
 *
 * @param code Identifier of the test being executed.
 * @param condition Boolean expression representing the test condition.
 *
 * @return 0 if the test passed, -1 if the test failed.
 */

int test(int code, bool condition)
{
  printf("Test #%d: ", code);
  if (condition)
  {
    printf("Passed!\n");
    return 0;
  }
  else
  {
    printf("Failed\nClearing memory...\n\n");
    return -1;
  }
}

#endif /* TEST_H */
