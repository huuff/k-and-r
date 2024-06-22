#include <stdbool.h>
#include <stdio.h>

int main() {
  bool inside_word = false;

  int nl, nw, nc;
  nl = nw = nc = 0;

  int c;
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n')
      ++nl;
    if (c == ' ' || c == '\n' || c == '\t')
      inside_word = false;
    else if (!inside_word) {
      inside_word = true;
      ++nw;
    }
  }

  printf("%d %d %d\n", nl, nw, nc);
}
