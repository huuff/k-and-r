#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Returns a string with the value that follows the given flag name
// Returns NULL if not found
char *get_flag_value(int argc, char *argv[], char *name) {
  // +2 to make space for the preceding dashes (e.g. --display)
  int flag_name_len = strlen(name) + 2;

  // the flag name including the dashes
  char flag_name[flag_name_len];
  sprintf(flag_name, "--%s", name);

  int flag_pos = -1;

  for (int i = 0; i < argc; i++) {
    if (strcmp(argv[i], flag_name) == 0) {
      flag_pos = i;
    }
  }

  if (flag_pos == -1) {
    // the given flag is not present
    return NULL;
  }

  int value_pos = flag_pos + 1;
  if (value_pos >= argc) {
    printf("Flag %s is not followed by its value\n", flag_name);
    // MAYBE print usage?
    exit(-1);
  }

  return argv[value_pos];
}

// Just a silly wrapper, does nothing, so almost unnecessary except to cleanly
// differentiate between getting string/int/float args.
char *get_str_arg(int argc, char *argv[], char *name) {
  return get_flag_value(argc, argv, name);
}
