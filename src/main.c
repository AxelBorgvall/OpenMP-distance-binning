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

  printf("number of threads = %d\nblocksize = %d\nfilepath=%s", threads,
         blocksize, fpath);

  // Set OpenMP threads
  omp_set_num_threads(threads);

  // Open the input file
  FILE *file = fopen(fpath, "r");
  if (!file) {
    fprintf(stderr, "Error: Could not open file '%s'\n", fpath);
    return 1;
  }

  // Compute total number of points using file size (fixed line length)
  if (fseek(file, 0, SEEK_END) != 0) {
    fprintf(stderr, "Error seeking to end of file\n");
    fclose(file);
    return 1;
  }

  long total_bytes = ftell(file);
  if (total_bytes % LINE_LEN != 0) {
    fprintf(stderr, "Warning: File size not multiple of line length; assuming "
                    "valid input\n");
  }

  long total_points_long = total_bytes / LINE_LEN;
  if (total_points_long > INT_MAX) {
    fprintf(stderr, "Error: Too many points (exceeds int)\n");
    fclose(file);
    return 1;
  }

  int total_points = (int)total_points_long;

  // Compute number of blocks
  int num_blocks = (total_points + blocksize - 1) / blocksize;

  // Allocate reusable blocks (two for A and B; check memory roughly)
  size_t block_mem = (size_t)blocksize * sizeof(Point);
  if (block_mem > 2 * 1024 * 1024 * 2) { // Rough check: <4 MiB for two blocks
    fprintf(stderr, "Error: Blocksize too large for memory limit\n");
    fclose(file);
    return 1;
  }

  printf("Number of lines=%d\nNumber of blocks=%d", total_points, num_blocks);

  // Define blocks

  // Loop over file

  return 0;
}
