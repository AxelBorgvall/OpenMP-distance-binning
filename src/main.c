#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/computation.h"
#include "../include/parsing.h"
#include "../include/point.h"

#define LINE_LEN 24
#define DEFAULT_BLOCKSIZE 10000

int main(int argc, char *argv[]) {

  int threads = 1;
  int blocksize = DEFAULT_BLOCKSIZE;
  char *fpath = "cells";

  // Parse command-line arguments
  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-t") == 0 && i + 1 < argc) {
      threads = atoi(argv[i + 1]);
      i++;

    } else if (strncmp(argv[i], "-t", 2) == 0) {
      threads = atoi(argv[i] + 2);

    } else if (strcmp(argv[i], "-n") == 0 && i + 1 < argc) {
      blocksize = atoi(argv[i + 1]);
      i++;

    } else if (strncmp(argv[i], "-n", 2) == 0) {
      blocksize = atoi(argv[i] + 2);

    } else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) {
      fpath = argv[i + 1];
      i++;

    } else {
      fprintf(stderr, "Unknown argument: %s\n", argv[i]);
      return 1;
    }
  }

  // Set OpenMP threads

  omp_set_num_threads(threads);

  // Open the input file

  FILE *file = fopen(fpath, "r");

  if (!file) {
    fprintf(stderr, "Error: Could not open file '%s'\n", fpath);
    return 1;
  }
  printf("number of threads = %d\n blocksize = %d\n filepath=%s", threads,
         blocksize, fpath);

  // Define blocks

  // Loop over file

  return 0;
}
