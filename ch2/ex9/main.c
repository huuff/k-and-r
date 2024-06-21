#include <stdbool.h>
#include <stdio.h>

int main() {
  int c;
  int blanks = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      blanks++;
    } else {
      blanks = 0;
    }

    if (blanks <= 1) {
      putchar(c);
    }
  }

  return 0;
}
