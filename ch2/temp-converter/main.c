#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

int get_int_arg(int argc, char* argv[], char* name, int default_value) {
  int flag_pos = -1;

  for (int i = 0; i < argc; i++) {
    if (strcmp(argv[i], name) == 0) {
      flag_pos = i;
    }
  }

  if (flag_pos == -1) {
    return default_value; 
  }

  int value_pos = flag_pos + 1;
  if (value_pos >= argc) {
    // TODO: There's no value, panic!
    return default_value;
  }

  char* value = argv[value_pos];
  if (!str_is_nat(value)) {
    // TODO: Same! Also panic!!!
    return default_value;
  }

  return atoi(value);
}

int main(int argc, char* argv[]) {
  int lower = get_int_arg(argc, argv, "lower", 0);
  int upper = get_int_arg(argc, argv, "upper", 300);
  int step = get_int_arg(argc, argv, "step", 20);

  for (float fahr = lower; fahr <= upper; fahr += step) {
    float celsius = (5.0/9.0) * (fahr-32.0);
    printf("%3.0f %6.1f\n", fahr, celsius);
  }

  return 0;
}
