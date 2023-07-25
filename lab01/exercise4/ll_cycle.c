// Copyright 2023 Sajid karim"
#include "ll_cycle.h"

#include <stddef.h>

int ll_has_cycle(node *head) {
  /* TODO: Implement ll_has_cycle */
  node *fast_ptr = head;
  node *slow_ptr = head;
  while (fast_ptr != NULL) {
    slow_ptr = slow_ptr->next;

    if (fast_ptr->next == NULL) {
      return 0;
    }
    fast_ptr = fast_ptr->next->next;

    if (slow_ptr == fast_ptr) {
      return 1;
    }
  }

  return 0;
}
