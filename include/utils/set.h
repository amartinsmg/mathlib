#ifndef SET_H
#define SET_H

#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Structure representing a node in the set's linked list.
 */
typedef struct SetLink_s
{
  long long data;         /**< The data stored in the node. */
  struct SetLink_s *next; /**< Pointer to the next node. */
} SetLink;

/**
 * @brief Structure representing a set of unique values.
 */
typedef struct
{
  SetLink *head; /**< Pointer to the head of the linked list. */
  size_t length; /**< The number of elements in the set. */
} Set;

/**
 * @brief Adds a value to the set.
 *
 * Checks if the value already exists in the set. If not, allocates a new node
 * and adds it to the beginning of the list.
 *
 * @param set Pointer to the Set structure.
 * @param value The value to add.
 *
 * @return 1 if the value was added, 0 if the value already exists,
 * or -1 if memory allocation failed.
 */
static inline int set_add_value(Set *set, long long value)
{
  long long *values = NULL;
  size_t i;
  SetLink *current = set->head;

  while (current != NULL)
  {
    if (current->data == value)
      return 0;
    current = current->next;
  }

  SetLink *new_node = (SetLink *)malloc(sizeof(*new_node));
  if (!new_node)
    return -1;
  new_node->data = value;
  new_node->next = set->head;
  set->head = new_node;
  set->length++;

  return 1;
}

/**
 * @brief Checks if a value is present in the set.
 *
 * @param set Pointer to the Set structure.
 * @param value The value to check for.
 *
 * @return True if the value is found, false otherwise.
 */
static inline bool set_contains(Set *set, long long value)
{
  SetLink *current = set->head;
  while (current != NULL)
  {
    if (current->data == value)
      return true;
    current = current->next;
  }
  return false;
}

/**
 * @brief Frees the memory allocated for the set's nodes.
 *
 * Iterates through the linked list and frees each node.
 *
 * @param set Pointer to the Set structure.
 */
static inline void set_free(Set *set)
{
  SetLink *current = set->head;
  while (current != NULL)
  {
    SetLink *next = current->next;
    free(current);
    current = next;
  }
}

/**
 * @brief Retrieves the values stored in the set as an array.
 *
 * @param set Pointer to the Set structure.
 *
 * @return A dynamically allocated array containing the values in the set.
 *
 * @note It is the caller's responsibility to free the allocated memory.
 */
static inline long long *set_get_values(Set *set)
{
  size_t i;
  SetLink *current = set->head;
  long long *values = (long long *)malloc(sizeof(*values) * set->length);
  for (i = 0; i < set->length; i++)
  {
    values[i] = current->data;
    current = current->next;
  }
  return values;
}

#endif /* SET_H */