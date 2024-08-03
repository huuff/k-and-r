#include "count.h"
#include "parseargs.h"
#include "printers.h"
#include <string.h>

int main(int argc, char **argv) {

  struct word_length word_length = count();

  char *display_mode = get_str_arg(argc, argv, "display");

  if ((display_mode == NULL) || (strcmp(display_mode, "plain") == 0)) {
    print_plain(word_length);
  } else if (strcmp(display_mode, "horizontal") == 0) {
    print_horizontal(word_length);
  }

  return 0;
}
