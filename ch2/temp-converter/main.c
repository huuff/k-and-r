#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Checks whether the given string is a natural number
bool str_is_nat(char* str) {
  for (int i = 0; str[i] != '\0'; i++) {
    char value = str[i];
    if (value < '0' || value > '9') {
      return false;
    }
  }

  return true;
}

int main(int argc, char* argv[]) {
  int lower = 0;
  if (argc >= 1) {
    char* arg = argv[1];
    if (str_is_nat(arg)) {
      lower = atoi(argv[1]);
    } else {
      printf("The string %s is not a natural number\n", arg);
      return -1;
    }
  }

  int upper = 300;
  if (argc >= 2) {
    char* arg = argv[2];
    if (str_is_nat(arg)) {
      upper = atoi(argv[2]);
    } else {
      printf("The string %s is not a natural number\n", arg);
      return -1;
    }
  }

  int step = 20;
  if (argc >= 3) {
    char* arg = argv[3];
    if (str_is_nat(arg)) {
      step = atoi(argv[3]);
    } else {
      printf("The string %s is not a natural number\n", arg);
      return -1;
    }
  }

  for (float fahr = lower; fahr <= upper; fahr += step) {
    float celsius = (5.0/9.0) * (fahr-32.0);
    printf("%3.0f %6.1f\n", fahr, celsius);
  }

  return 0;
}
