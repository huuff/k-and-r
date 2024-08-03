#include "count.h"
#include "printers.h"

int main(int argc, char **argv) {

  struct word_length word_length = count();
  print_plain(word_length);

  return 0;
}
