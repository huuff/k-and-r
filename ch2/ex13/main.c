#include <stdio.h>
#include <stdlib.h>

// TODO: Implement a vertical histogram
// TODO: Try to decide whether to use plaintext, horizontal or vertical
// histogram from some command-line argument

// Surely some random german word is this long
#define MAX_WORD_LENGTH 128

struct word_length_bounds {
  int min;
  int max;
};
struct word_length_bounds find_word_length_bounds(int *word_lengths);
void print_lengths_plaintext(int *word_lengths,
                             struct word_length_bounds *bounds);
void print_horizontal_histogram(int *word_lengths,
                                struct word_length_bounds *bounds);

int main() {
  int word_lengths[MAX_WORD_LENGTH];

  for (int i = 0; i < MAX_WORD_LENGTH; ++i) {
    word_lengths[i] = 0;
  }

  int current_word_length = 0;
  int c;

  while ((c = getchar()) != EOF) {
    if (c == '\n' || c == ' ' || c == '\t') {
      if (current_word_length > 0) {
        word_lengths[current_word_length]++;
        current_word_length = 0;
      }
    } else {
      current_word_length++;
    }
  }

  // A final pass for the last word if it's not followed by a blank
  if (current_word_length > 0) {
    word_lengths[current_word_length]++;
  }

  struct word_length_bounds word_length_bounds =
      find_word_length_bounds(word_lengths);

  if (word_length_bounds.min == -1 || word_length_bounds.max == -1) {
    fprintf(stderr, "No words found!\n");
    exit(1);
  }

  // print_lengths_plaintext(word_lengths, &word_length_bounds);
  print_horizontal_histogram(word_lengths, &word_length_bounds);

  return 0;
}

void print_lengths_plaintext(int *word_lengths,
                             struct word_length_bounds *bounds) {

  for (int i = bounds->min; i <= bounds->max; ++i) {
    printf("Length %d: %d\n", i, word_lengths[i]);
  }
}

void print_horizontal_histogram(int *word_lengths,
                                struct word_length_bounds *bounds) {
  for (int i = bounds->min; i <= bounds->max; ++i) {
    printf("Length %d:\t ", i);
    int count = word_lengths[i];
    for (int j = 0; j < count; j++) {
      printf("*");
    }
    printf("\n");
  }
}

// Finds the minimum and maximum index that has a count larger than 0,
// to decide what axis bounds to show on the histogram
struct word_length_bounds find_word_length_bounds(int *word_lengths) {
  struct word_length_bounds word_length_bounds = {-1, -1};

  for (int i = 0; i < MAX_WORD_LENGTH; ++i) {
    if (word_lengths[i] > 0) {
      word_length_bounds.min = i;
      break;
    }
  }

  for (int i = 0; i < MAX_WORD_LENGTH; i++) {
    if (word_lengths[i] > 0) {
      word_length_bounds.max = i;
    }
  }

  return word_length_bounds;
}
