#include "count.h"
#include "stdio.h"

void print_plain(struct word_length word_length) {
  for (int i = word_length.min; i <= word_length.max; i++) {
    printf("Length %d: %d\n", i, word_length.count[i]);
  }
}

void print_horizontal(struct word_length word_length) {
  for (int i = word_length.min; i <= word_length.max; i++) {
    printf("Length %d: ", i);
    for (int j = 0; j < word_length.count[i]; j++) {
      putchar('#');
    }
    printf("\n");
  }
}
