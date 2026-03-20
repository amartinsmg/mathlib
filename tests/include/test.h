#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <stdlib.h>

#define ASSERT_TRUE(condition)                   \
  if (!(condition))                              \
  {                                              \
    printf("FAIL: %s:%d\n", __FILE__, __LINE__); \
    return EXIT_FAILURE;                         \
  }

#endif /* TEST_H */
