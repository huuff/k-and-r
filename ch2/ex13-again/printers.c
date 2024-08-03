#include "count.h"
#include "stdio.h"

void print_plain(struct word_length word_length) {
  printf("Min length: %d\n", word_length.min);
  printf("Max length: %d\n", word_length.max);

  for (int i = word_length.min; i <= word_length.max; i++) {
    printf("Length %d: %d\n", i, word_length.count[i]);
  }
}
