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

  static long long ids[100000];
  int n = 0;
  long long total = 0;

  for (long long mult = 10; mult <= 100000; mult *= 10) {
    for (long long chunk = mult / 10; chunk <= mult - 1; chunk++) {
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

      long long start = strtoll(p, &endptr, 10);

      // duck out if nothing more to look at
      if (p == endptr) {
        break;
      }

      p = endptr;

      if (*p != '-') {
        break;
      }
      p++;

      long long end = strtoll(p, &endptr, 10);
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
  printf("%lld\n", total);
  fclose(fp);
  return 0;
}
