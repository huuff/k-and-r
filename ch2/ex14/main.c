#include "count.h"
#include <stdio.h>

int main() {
  int *char_count = count();

  for (int i = 0; i < MAX_CHAR; i++) {
    int ccount = char_count[i];
    if (i != '\n' && ccount > 0) {
      printf("%c: ", i);
      for (int j = 0; j < ccount; j++) {
        putchar('#');
      }
      putchar('\n');
    }
  }

  return 0;
}
