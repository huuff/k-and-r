#include <stdio.h>

int main() {
  long spaces = 0;
  long tabs = 0;
  long newlines = 0;

  int c;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      spaces++;
    } else if (c == '\t') {
      tabs++;
    } else if (c == '\n') {
      newlines++;
    }
  }

  printf("Spaces: %ld\nTabs: %ld\nNewlines: %ld\n", spaces, tabs, newlines);
}
