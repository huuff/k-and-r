#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Checks whether the given string is a natural number
bool str_is_int(char* str) {
  for (int i = 0; str[i] != '\0'; i++) {
    char value = str[i];
    if (value != '-' && (value < '0' || value > '9')) {
      return false;
    }
  }

  return true;
}

int get_int_arg(
    int argc, 
    char* argv[], 
    char* name, 
    int default_value
) {
  int flag_name_len = strlen(name) + 2;
  char flag_name[flag_name_len];
  sprintf(flag_name, "--%s", name);

  int flag_pos = -1;

  for (int i = 0; i < argc; i++) {
    if (strcmp(argv[i], flag_name) == 0) {
      flag_pos = i;
    }
  }

  if (flag_pos == -1) {
    return default_value; 
  }

  int value_pos = flag_pos + 1;
  if (value_pos >= argc) {
    printf("Flag %s is not followed by its value\n", flag_name);
    exit(-1);
  }

  char* value = argv[value_pos];
  if (!str_is_int(value)) {
    printf("Value %s is not an integer\n", value);
    exit(-1);
  }

  return atoi(value);
}

float fahr_to_celsius(float fahr) {
  return (5.0/9.0) * (fahr - 32.0);
}

int main(int argc, char* argv[]) {
  int lower = get_int_arg(argc, argv, "lower", 0);
  int upper = get_int_arg(argc, argv, "upper", 300);
  int step = get_int_arg(argc, argv, "step", 20);

  for (float fahr = lower; fahr <= upper; fahr += step) {
    printf("%3.0f %6.1f\n", fahr, fahr_to_celsius(fahr));
  }

  return 0;
}
