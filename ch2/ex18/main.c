#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define TAB '\t'
#define SPACE ' '
#define NEWLINE '\n'
#define MAX_LINE 1024

int find_last_nonblank_pos(char *line, ssize_t line_len) {
  int result = -1;

  for (int i = 0; i < line_len; i++) {
    if (line[i] != TAB && line[i] != SPACE && line[i] != NEWLINE) {
      result = i;
    }
  }

  return result;
}

int main() {
  char *line = malloc(MAX_LINE);
  ssize_t line_len;

  // This line is just so I can take a pointer to it
  size_t max_line = MAX_LINE;
  while ((line_len = getline(&line, &max_line, stdin)) != -1) {
    int last_nonblank_pos = find_last_nonblank_pos(line, line_len);
    for (int i = 0; i <= last_nonblank_pos; i++) {
      putchar(line[i]);
    }

    if (last_nonblank_pos > 0) {
      putchar('\n');
    }
  }

  return 0;
}
