#include "count.h"
#include "stdio.h"
#include <stdlib.h>

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

void print_vertical(struct word_length word_length) {
  int max_count = -1;

  for (int i = word_length.min; i <= word_length.max; i++) {
    int current_length_count = word_length.count[i];
    if (current_length_count > max_count) {
      max_count = current_length_count;
    }
  }

  if (max_count == -1) {
    printf("Did you even write anything?");
    exit(1);
  }

  for (int i = max_count; i > 0; i--) {
    for (int j = word_length.min; j <= word_length.max; j++) {
      if (word_length.count[j] >= i) {
        printf("#");
      } else {
        printf(" ");
      }
      printf(" ");
    }
    printf("\n");
  }

  for (int i = word_length.min; i <= word_length.max; i++) {
    printf("%d ", i);
  }
  printf("\n");
}
