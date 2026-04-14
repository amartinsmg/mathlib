#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Structure representing a dynamic vector.
 */
typedef struct
{
  char *data;       /**< Pointer to the allocated memory buffer. */
  size_t data_size; /**< Size of each element in bytes. */
  size_t length;    /**< Number of elements currently in the vector. */
  size_t capacity;
} Vector;

/**
 * @brief Initializes a new vector.
 *
 * @param data_size The size of each element to be stored in the vector.
 *
 * @return An initialized Vector structure with zero length.
 */
static inline Vector vector_init(size_t data_size)
{
  Vector v = {0};
  v.data_size = data_size;
  return v;
}

/**
 * @brief Appends a value to the vector.
 *
 * Reallocates the vector's memory to accommodate the new value and copies it to the end.
 *
 * @param v Pointer to the Vector structure.
 * @param value Pointer to the value to be appended.
 *
 * @return 1 if the value was successfully added, or -1 if memory reallocation failed.
 */

static inline int vector_append(Vector *v, void *value)
{
  if (v->length == v->capacity)
  {
    size_t new_capacity = v->capacity ? v->capacity * 2 : 4;

    char *tmp = (char *)realloc(v->data, new_capacity * v->data_size);
    if (!tmp)
      return -1;

    v->capacity = new_capacity;
    v->data = tmp;
  }

  memcpy(v->data + v->length * v->data_size, value, v->data_size);

  v->length++;

  return 0;
}

/**
 * @brief Frees the memory allocated for the vector.
 *
 * Releases the memory buffer used by the vector and resets its length.
 *
 * @param v Pointer to the Vector structure.
 */

static inline void vector_free(Vector *v)
{
  free(v->data);
  v->length = 0;
}

/**
 * @brief Retrieves the values stored in the vector as an array.
 *
 * @param v Pointer to the Vector structure.
 *
 * @return A pointer to a dynamically allocated array containing the values.
 *
 * @note It is the caller's responsibility to free the allocated memory.
 */

static inline void *vector_get_values(Vector *v)
{
  char *values = (char *)malloc(v->data_size * v->length);

  memcpy(values, v->data, v->length * v->data_size);

  return values;
}

#endif /* VECTOR_H */