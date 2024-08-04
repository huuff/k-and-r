#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 1000

int main() {
  size_t max_line = MAX_LINE;
  char *line = malloc(max_line);

  ssize_t line_len;

  while ((line_len = getline(&line, &max_line, stdin)) != -1) {
    if (line_len > 80) {
      printf("%s", line);
    }
  }

  return 0;
}
