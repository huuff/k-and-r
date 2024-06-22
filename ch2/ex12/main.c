#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

struct current_word {
  int length;
  char buffer[64];
};

int main() {
  bool inside_word = false;
  struct current_word current_word = {0};

  int c;
  while ((c = getchar()) != EOF) {
    if (isblank(c) || c == '\n') {
      if (current_word.length > 0) {
        current_word.buffer[current_word.length] = '\0';
        printf("%s\n", current_word.buffer);
      }
      current_word.length = 0;
    } else {
      current_word.buffer[current_word.length++] = (char)c;
    }
  }

  // TODO: Extract this behavior to a function?
  if (current_word.length > 0) {
    current_word.buffer[current_word.length] = '\0';
    printf("%s", current_word.buffer);
  }

  return 0;
}
