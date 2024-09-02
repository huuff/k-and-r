#include <stdio.h>
#include <stdlib.h>

char *reverse(char *input);

int main() {
  char *input = "hola que tal";

  char *reversed = reverse(input);

  printf("input: %s\n", input);
  printf("output: %s\n", reversed);

  return 0;
}

char *reverse(char *input) {
  int size = -1;

  for (int i = 0; input[i] != '\0'; i++) {
    size++;
  }

  char *output = malloc((size + 1) * sizeof(char));

  for (int i = 0; i < size; i++) {
    output[i] = input[size - i];
  }
  output[size] = '\0';

  return output;
}
