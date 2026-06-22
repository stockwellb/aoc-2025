#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  const char *filename = argc > 1 ? argv[1] : "input.txt";
  printf("Advent of Code 2025 - Day 02\n");
  printf("Using input: %s\n", filename);

  int64_t ceiling = 100000000000LL;

  FILE *fp = fopen(filename, "r");

  if (!fp) {
    return 1;
  }

  static int64_t ids[110000];
  int n = 0;
  bool over = false;
  // int64_t total = 0;

  for (int64_t mult = 10; mult <= 100000; mult *= 10) {
    int64_t lo = mult / 10;
    for (int reps = 2; reps <= 4; reps++) {
      over = false;
      for (int64_t chunk = lo; chunk <= mult - 1; chunk++) {
        int64_t id = 0;
        for (int r = 0; r < reps; r++) {
          id = id * mult + chunk; // Horner concat
          over = id > ceiling;
          if (over) {
            break;
          }
        }
        if (over) {
          break;
        }
        ids[n++] = id;
        printf("%lld\n", id);
      }
    }
  }

  /*

  char line[10000]; // hard limit which is fine for this task

  while (fgets(line, sizeof(line), fp)) {
    char *p = line;
    while (*p) {
      // scoot past any junk
      while (*p == ',' || *p == ' ' || *p == '\n' || *p == '\t')
        p++;

      // duck out if \0
      if (!*p)
        break;

      char *endptr;

      int64_t start = strtoll(p, &endptr, 10);

      // duck out if nothing more to look at
      if (p == endptr) {
        break;
      }

      p = endptr;

      if (*p != '-') {
        break;
      }
      p++;

      int64_t end = strtoll(p, &endptr, 10);
      if (p == endptr)
        break;
      p = endptr;

      for (int i = 0; i < n; i++) {
        if (ids[i] > end) {
          break;
        }
        if (ids[i] >= start) {
          total += ids[i];
        }
      }
    }
  }
  printf("%" PRId64 "\n", total);
  */
  fclose(fp);
  return 0;
}
