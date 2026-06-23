#include <aoc.h>
#include <inttypes.h>
#include <stdbool.h>
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

  id_list list = id_list_create(5, 2, 2);
  int64_t total = 0;

  char line[10000]; // hard limit which is fine for this task

  while (fgets(line, sizeof(line), fp)) {
    char *p = line;
    int64_t start, end;
    while (parse_range(&p, &start, &end)) {
      total += sum_ids_in_range(list, start, end);
    }
  }
  printf("%" PRId64 "\n", total);
  fclose(fp);
  id_list_free(list);
  return 0;
}
