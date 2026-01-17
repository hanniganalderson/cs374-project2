#include "scanner.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  const char *dirpath;
  const char *printname;
  long result;

  if (argc > 2) {
    fprintf(stderr, "usage: filescanner [directory]\n");
    return 1;
  }
  if (argc == 1) {
    dirpath = ".";
    printname = ".";
  } else {
    dirpath = argv[1];
    printname = argv[1];
  }
  result = scan_directory(dirpath, printname);

  if (result == -1) {
    return 1;
  }
  return 0;
}