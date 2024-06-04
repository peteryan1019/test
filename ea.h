#ifndef _EA_H
#define _EA_H

#include <stdlib.h>
#include <stdio.h>

// ea = expandable array. You may have seen this in B63. :)
struct ea {
  int *data;         // malloc'ed actual array of elements
  size_t capacity;   // how large that array is
  size_t n;          // but only 0 ... n-1 are in use
};

// Create and initialize a dynamically allocated ea.
// If allocation fails, returns NULL.
struct ea *create(void);

// Add one more element at the end.
void add(struct ea *p, int x);

// Free a dynamically allocated ea. Inverse of create().
void destroy(struct ea *p);

// There should also be functions for accessing content but omitted for this lab.

#endif
