#include "count.h"
#include <stdbool.h>
#include <stdio.h>

void count_word(struct word_length *word_length, int current_word_length);

struct word_length count() {
  struct word_length result;
  result.min = 200000; // high value so anything is lower than this... can't I
  // use something like int::MAX?
  result.max = -1; // the opposite of above

  for (int i = 0; i < MAX_WORD_LENGTH; i++) {
    result.count[i] = 0;
  }

  int current_char;
  int current_word_length = 0;

  for (int current_char = getchar();
       current_char != EOF && current_char != '\n'; current_char = getchar()) {
    if (current_char == ' ' || current_char == '\t' || current_char == '\n') {
      count_word(&result, current_word_length);
      current_word_length = 0;
    } else {
      current_word_length++;
    }
  }

  // Add the last word if there's any
  count_word(&result, current_word_length);

  return result;
}

void count_word(struct word_length *word_length, int current_word_length) {
  if (current_word_length > 0) {
    word_length->count[current_word_length]++;
    if (current_word_length < word_length->min) {
      word_length->min = current_word_length;
    }
    if (current_word_length > word_length->max) {
      word_length->max = current_word_length;
    }
  }
}
