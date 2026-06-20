#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  const char *filename = argc > 1 ? argv[1] : "input.txt";
  printf("Advent of Code 2025 - Day 02\n");
  printf("Using input: %s\n", filename);

  FILE *fp = fopen(filename, "r");

  if (!fp) {
    return 1;
  }

  static int64_t ids[100000];
  int n = 0;
  int64_t total = 0;

  for (int64_t mult = 10; mult <= 100000; mult *= 10) {
    for (int64_t chunk = mult / 10; chunk <= mult - 1; chunk++) {
      ids[n++] = chunk * mult + chunk;
    }
  }

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
  fclose(fp);
  return 0;
}
