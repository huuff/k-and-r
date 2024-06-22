#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

struct current_word {
  int length;
  char buffer[64];
};

void print_current_word(struct current_word *current_word);

int main() {
  bool inside_word = false;
  struct current_word current_word = {0};

  int c;
  while ((c = getchar()) != EOF) {
    if (isblank(c) || c == '\n') {
      print_current_word(&current_word);
    } else {
      current_word.buffer[current_word.length++] = (char)c;
    }
  }

  if (current_word.length > 0) {
    print_current_word(&current_word);
  }

  return 0;
}

void print_current_word(struct current_word *current_word) {
  if (current_word->length > 0) {
    current_word->buffer[current_word->length] = '\0';
    printf("%s\n", current_word->buffer);
    current_word->length = 0;
  }
}
