#include <aoc.h>
#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  const char *filename = argc > 1 ? argv[1] : "input.txt";
  printf("Advent of Code 2025 - Day 03\n");
  printf("Using input: %s\n", filename);

  FILE *fp = fopen(filename, "r");

  if (!fp) {
    return 1;
  }

  char line[128];
  int64_t total = 0;

  while (fgets(line, sizeof(line), fp)) {
    size_t len = strlen(line);
    int running_max = 0;
    int best = 0;
    for (int i = (int)len - 1; i >= 0; i--) {
      if (!isdigit((unsigned char)line[i]))
        continue;
      int d = line[i] - '0';
      int candidate = d * 10 + running_max;
      if (running_max > 0 && candidate > best) {
        best = candidate;
      }
      if (d > running_max) {
        running_max = d;
      }
    }
    total += best;
  }
  printf("Total: %" PRId64 "\n", total);
  return 0;
}
