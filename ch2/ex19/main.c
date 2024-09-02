#include <stdio.h>
#include <stdlib.h>

char *reverse(char *input);

int main() {
  char input[4096];

  int c;
  int pos = 0;

  while ((c = getchar()) != EOF) {
    input[pos++] = c;
  }

  input[pos] = '\0';

  char *output = reverse(input);

  printf("\n%s\n", output);

  return 0;
}

char *reverse(char *input) {
  int size = 0;

  for (int i = 0; input[i] != '\0'; i++) {
    size++;
  }

  char *output = malloc((size) * sizeof(char));

  for (int i = 0; i < size; i++) {
    output[i] = input[size - i - 1];
  }
  output[size] = '\0';

  return output;
}
