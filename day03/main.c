#include <aoc.h>
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

  char line[100];

  while (fgets(line, sizeof(line), fp)) {
    for (char *p = line; *p && *p != '\n'; p++) {
      printf("%c\n", *p);
    }
  }

  return 0;
}
