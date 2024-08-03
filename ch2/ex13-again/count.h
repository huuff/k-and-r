#pragma once

#define MAX_WORD_LENGTH 128

struct word_length {
  int min;
  int max;
  int count[MAX_WORD_LENGTH];
};

struct word_length count();
