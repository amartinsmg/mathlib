#ifndef SET_H
#define SET_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * @brief Structure representing a set of unique values.
 */

typedef struct
{
  char *data;       /**< Pointer to the allocated memory buffer. */
  size_t data_size; /**< Size of each element in bytes. */
  size_t length;    /**< Number of elements currently in the set. */
  size_t capacity;  /**< Total number of elements the set can hold before reallocating. */
} Set;

/**
 * @brief Initializes a new set.
 *
 * @param data_size The size of each element in bytes.
 *
 * @return An initialized Set structure with zero length.
 */

static inline Set set_init(size_t data_size)
{
  Set s = {0};
  s.data_size = data_size;
  return s;
}


/**
 * @brief Checks if a value is present in the set.
 *
 * @param s Pointer to the Set structure.
 * @param value Pointer to the value to check for.
 *
 * @return True if the value is found, false otherwise.
 */

static inline bool set_contains(Set *s, void *value)
{
  size_t i;

  for (i = 0; i < s->length; i++)
  {
    if (!memcmp(s->data + i * s->data_size, value, s->data_size))
      return true;
  }

  return false;
}

/**
 * @brief Adds a value to the set.
 *
 * Checks if the value already exists in the set. If not, grows the internal
 * buffer if necessary and appends the new value.
 *
 * @param set Pointer to the Set structure.
 * @param value Pointer to the value to add.
 *
 * @return 1 if the value was added, 0 if it already exists, or -1 if memory allocation failed.
 */

static inline int set_add_value(Set *set, void *value)
{
  if (set_contains(set, value))
    return 0;

  if (set->length == set->capacity)
  {
    size_t new_capacity = set->capacity ? set->capacity * 2 : 4;

    char *tmp = (char *)realloc(set->data, new_capacity * set->data_size);
    if (!tmp)
      return -1;

    set->capacity = new_capacity;
    set->data = tmp;
  }

  memcpy(set->data + set->length * set->data_size, value, set->data_size);

  set->length++;

  return 1;
}

/**
 * @brief Frees the memory allocated for the set.
 *
 * @param set Pointer to the Set structure to be cleared.
 */

static inline void set_free(Set *set)
{
  free(set->data);
  set->length = 0;
  set->capacity = 0;
}

/**
 * @brief Retrieves the values stored in the set as an array.
 *
 * @param s Pointer to the Set structure.
 *
 * @return A dynamically allocated array containing the values in the set.
 *
 * @note It is the caller's responsibility to free the allocated memory.
 */

static inline void *set_get_values(Set *s)
{
  char *values = (char *)malloc(s->data_size * s->length);

  memcpy(values, s->data, s->length * s->data_size);

  return values;
}

#endif /* SET_H */