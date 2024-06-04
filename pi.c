/* Compile:
 * 
 * gcc -O2 -Wall -g ea.c pi.c -o pi
 *
 * -g records "debugging information" such as source code line numbers so
 * valgrind (and other debugging tools) can report line numbers.
 *
 * Run under valgrind:
 *
 * valgrind --leak-check=yes ./pi
 */

#include <stdlib.h>
#include <stdio.h>
#include "ea.h"

void print_ea(const struct ea *p) {
  printf("<");
  for (size_t i = 0; i < p->n; i++) {
    printf("%d ", p->data[i]);
  }
  printf(">\n");
}

int main(void)
{
  struct ea *a = create();
  if (a == NULL) exit(1);
  int pi[] = { 3, 1, 4, 1, 5, 9 };
  for (int i = 0; i < sizeof(pi)/sizeof(int); i++) {
    add(a, pi[i]);
    print_ea(a);
  }
  destroy(a);
  return 0;
}

// When marking, a different file with a different main will be used.
