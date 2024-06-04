#include <stdlib.h>
#include <stdio.h>
#include "ea.h"

// Create and initialize a dynamically allocated ea.
// If allocation fails, returns NULL.
struct ea *create(void) {
  struct ea *p = calloc(1, sizeof(struct ea *));
  if (p == NULL) {
    return NULL;
  }
  p->capacity = 1;
  p->n = 0;
  p->data = calloc(p->capacity, sizeof(int));
  if (p->data == NULL) {
    free(p);
    return NULL;
  }
  return p;
}

// Add one more element at the end.
void add(struct ea *p, int x) {
  if (p->capacity == p->n) {
    // Full, move to larger space.
    size_t new_capacity = 2 * p->capacity;
    int *new_home = realloc(p->data, new_capacity);
    if (new_home == NULL) {
      // For simplicity we abort.
      fprintf(stderr, "Failed to expand. Aborting.\n");
      exit(1);
    }
    p->capacity = new_capacity;
    free(new_home);
  }
  p->data[p->n++] = x;
}

// Free a dynamically allocated ea. Inverse of create().
void destroy(struct ea *p) {
  free(p);
}

// There should also be functions for accessing content but omitted for this lab.
