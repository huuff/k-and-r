#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

int main() {
  bool inside_word = false;
  char buffered_word[64];
  int word_length = 0;

  int c;
  while ((c = getchar()) != EOF) {
    if (isblank(c)) {
      if (word_length > 0) {
        buffered_word[word_length] = '\0';
        printf("%s\n", buffered_word);
      }
      word_length = 0;
    } else {
      buffered_word[word_length++] = (char)c;
    }
  }

  // TODO: Extract this behavior to a function?
  if (word_length > 0) {
    buffered_word[word_length] = '\0';
    printf("%s", buffered_word);
  }

  return 0;
}
