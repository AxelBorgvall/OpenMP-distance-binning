#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  int n = 10; // default number of datapoints
  if (argc > 1) {
    n = atoi(argv[1]);
  }
  if (n <= 0) {
    n = 10; // ensure positive
  }

  srand(time(NULL));

  FILE *file = fopen("cells.txt", "w");
  if (file == NULL) {
    fprintf(stderr, "Error opening cells.txt for writing\n");
    return 1;
  }

  for (int i = 0; i < n; i++) {
    for (int coord = 0; coord < 3; coord++) {
      double x = -10.0 + 20.0 * (rand() / (double)RAND_MAX);
      int sign = (x >= 0) ? 1 : -1;
      double absx = fabs(x);
      int intpart = (int)absx;
      double frac = absx - intpart;
      int fracint = (int)(frac * 1000.0 + 0.5); // round to nearest
      if (coord > 0) {
        fprintf(file, " ");
      }
      fprintf(file, "%c%02d.%03d", (sign == 1 ? '+' : '-'), intpart, fracint);
    }
    fprintf(file, "\n");
  }

  fclose(file);
  return 0;
}
