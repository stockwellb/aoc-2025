#include <stdio.h>

int main(int argc, char **argv) {
  const char *filename = argc > 1 ? argv[1] : "input.txt";
  printf("Advent of Code 2025 - Day 01\n");
  printf("Using input: %s\n", filename);

  if (!freopen(filename, "r", stdin)) {
    perror(filename);
    return 1;
  }

  char dir;
  int dist;
  int pos = 50;
  int count = 0;

  while (scanf(" %c%d", &dir, &dist) == 2) {
    if (dir == 'L') {
      dist = -dist;
    }
    pos = (pos + dist) % 100;
    if (pos < 0)
      pos += 100;
    if (pos == 0) {
      count++;
    }
  }

  printf("password = %d\n", count);

  return 0;
}
