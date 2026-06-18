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

  // scan ignoring whitespace and looking for two things.
  // a) a char
  // b) a number
  while (scanf(" %c%d", &dir, &dist) == 2) {
    if (dir == 'L') {
      dist = -dist;
    }

    // floored mod because C's mod is truncated.
    pos = (pos + dist) % 100;
    if (pos < 0) {
      pos += 100;
    }

    // The safe was a distraction.
    // The password is the number of times that we
    // land on zero.
    if (pos == 0) {
      count++;
    }
  }

  printf("password = %d\n", count);

  return 0;
}
