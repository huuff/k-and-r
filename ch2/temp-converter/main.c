#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_usage();
bool str_is_int(char *str);
char *get_flag_value(int argc, char *argv[], char *name);
int get_int_arg(int argc, char *argv[], char *name, int default_value);
char *get_str_arg(int argc, char *argv[], char *name, char *default_value);
float fahr_to_celsius(float fahr);
void print_header(int columnc, char *columns[]);

int main(int argc, char *argv[]) {
  int lower = get_int_arg(argc, argv, "lower", 0);
  int upper = get_int_arg(argc, argv, "upper", 300);
  int step = get_int_arg(argc, argv, "step", 20);

  if (upper < lower) {
    printf("The upper bound (%d) can't be lower than the lower bound (%d)\n",
           upper, lower);
    exit(-1);
  }

  char *target = get_str_arg(argc, argv, "to", "celsius");
  if (strcmp(target, "celsius") && strcmp(target, "fahrenheit")) {
    printf("The target (%s) must be either 'fahrenheit' or 'celsius'\n",
           target);
    exit(-1);
  }

  char *columns[] = {"Fahrenheit", "Celsius"};
  print_header(2, columns);
  for (float fahr = lower; fahr <= upper; fahr += step) {
    printf("%10.0f %10.1f\n", fahr, fahr_to_celsius(fahr));
  }

  return 0;
}

void print_usage() {
  printf("Usage: \n");
  printf("  --lower <num>\t- Minimum bound for the table\n");
  printf("  --upper <num>\t- Maximum bound for the table\n");
  printf("  --step <num>\t- Amount to increase for each row of the table\n");
}

void print_header(int columnc, char *columns[]) {
  for (int i = 0; i < columnc; i++) {
    printf("%10s", columns[i]);
  }
  printf("\n");
  for (int i = 0; i < columnc; i++) {
    printf("===========");
  }
  printf("\n");
}

// Checks whether the given string is a natural number
bool str_is_int(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    char value = str[i];
    if (value != '-' && (value < '0' || value > '9')) {
      return false;
    }
  }

  return true;
}

// Finds the value given to some flag (i.e. the value following it)
char *get_flag_value(int argc, char *argv[], char *name) {
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
    return NULL;
  }

  int value_pos = flag_pos + 1;
  if (value_pos >= argc) {
    printf("Flag %s is not followed by its value\n", flag_name);
    print_usage();
    exit(-1);
  }

  return argv[value_pos];
}

int get_int_arg(int argc, char *argv[], char *name, int default_value) {
  char *value = get_flag_value(argc, argv, name);

  if (value == NULL) {
    return default_value;
  }

  if (!str_is_int(value)) {
    printf("Value %s is not an integer\n", value);
    print_usage();
    exit(-1);
  }

  return atoi(value);
}

char *get_str_arg(int argc, char *argv[], char *name, char *default_value) {
  char *value = get_flag_value(argc, argv, name);

  if (value == NULL) {
    return default_value;
  }

  return value;
}

float fahr_to_celsius(float fahr) { return (5.0 / 9.0) * (fahr - 32.0); }
