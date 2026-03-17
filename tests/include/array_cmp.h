#include <stdbool.h>

#ifndef ARRAY_CMP_H
#define ARRAY_CMP_H

/**
  @brief Compare two arrays element by element.
  This function compares two arrays of long long integers, element by element, up to the specified length.
  If all elements in the arrays are equal, the function returns true. Otherwise, it returns false.
  @param arr1 The first array to compare.
  @param arr2 The second array to compare.
  @param length The length of the arrays.
  @return True if the arrays are equal, false otherwise.
*/

bool arrayCmp(long long *arr1, long long *arr2, unsigned length)
{
  unsigned i;
  for (i = 0; arr1[i] == arr2[i]; i++)
    if (i == length - 1)
      return true;
  return false;
}

#endif /* ARRAY_CMP_H */
