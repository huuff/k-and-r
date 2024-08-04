#include <stdio.h>
#include "count.h"
#include <stdlib.h>

int *count() {
  int *result = malloc(sizeof(int) * MAX_CHAR);
  int c;

  for (int i = 0; i < MAX_CHAR; i++) {
    result[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    result[c]++;
  }

  return result;
}
