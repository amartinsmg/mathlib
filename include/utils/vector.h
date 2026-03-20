#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

/**
 * @brief Structure representing a node in the vector's linked list.
 */

typedef struct VectorNode_s
{
  uint64_t data;             /**< The data stored in the node. */
  struct VectorNode_s *next; /**< Pointer to the next node. */
} VectorNode;

/**
 * @brief Structure representing a vector of values.
 */

typedef struct
{
  VectorNode *tail; /**< Pointer to the tail of the linked list. */
  size_t length;    /**< The number of elements in the vector. */
} Vector;

/**
 * @brief Appends a value to the vector.
 *
 * Allocates a new node containing the value and adds it to the vector.
 *
 * @param vector Pointer to the Vector structure.
 * @param value The value to append.
 *
 * @return 1 if the value was added, or -1 if memory allocation failed.
 */

static inline int vector_append(Vector *vector, uint64_t value)
{
  VectorNode *new_node = (VectorNode *)malloc(sizeof(*new_node));
  if (!new_node)
    return -1;

  new_node->data = value;
  new_node->next = vector->tail;
  vector->tail = new_node;
  vector->length++;

  return 1;
}

/**
 * @brief Frees the memory allocated for the vector's nodes.
 *
 * Iterates through the linked list and frees each node.
 *
 * @param vector Pointer to the Vector structure.
 */

static inline void vector_free(Vector *vector)
{
  VectorNode *current = vector->tail,
             *next = NULL;

  while (current != NULL)
  {
    next = current->next;
    free(current);
    current = next;
  }
  vector->tail = NULL;
  vector->length = 0;
}

/**
 * @brief Retrieves the values stored in the vector as an array.
 *
 * @param vector Pointer to the Vector structure.
 *
 * @return A dynamically allocated array containing the values in the vector.
 *
 * @note It is the caller's responsibility to free the allocated memory.
 */

static inline uint64_t *vector_get_values(Vector *vector)
{
  size_t i;
  VectorNode *current = vector->tail;

  uint64_t *values = (uint64_t *)malloc(sizeof(*values) * vector->length);

  for (i = 0; i < vector->length; i++)
  {
    values[vector->length - 1 - i] = current->data;
    current = current->next;
  }

  return values;
}

#endif /* VECTOR_H */