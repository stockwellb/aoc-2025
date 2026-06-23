#include "aoc.h"
#include "assert.h"
#include <stdint.h>

int cmp_int64(const void *a, const void *b) {
  int64_t x = *(int64_t *)a, y = *(int64_t *)b;
  return (x > y) - (x < y);
}

id_list id_list_create(int max_digits, int min_reps, int max_reps) {
  assert(max_digits >= 1 && max_digits <= 9);
  int64_t ceiling = 100000000000LL;
  int64_t size = 1;
  for (int i = 1; i <= max_digits; i++) {
    size *= 10;
  }

  int64_t *ids = malloc(size * sizeof(*ids));

  if (ids == NULL) {
    fprintf(stderr, "out of memory\n");
    exit(EXIT_FAILURE);
  }

  int n = 0;
  bool over = false;
  for (int64_t mult = 10; mult <= size; mult *= 10) {
    int64_t lo = mult / 10;
    for (int reps = min_reps; reps <= max_reps; reps++) {
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
      }
    }
  }

  qsort(ids, n, sizeof(*ids), cmp_int64);

  // deduplicate
  int unique = 0;
  for (int i = 0; i < n; i++) {
    if (unique == 0 || ids[i] != ids[unique - 1]) {
      ids[unique++] = ids[i];
    }
  }

  return (id_list){.ids = ids, .count = unique};
}

void id_list_free(id_list list) { free(list.ids); }

int64_t sum_ids_in_range(id_list list, int64_t start, int64_t end) {
  int64_t total = 0;

  for (int i = 0; i < list.count; i++) {
    if (list.ids[i] > end) {
      break;
    }
    if (list.ids[i] >= start) {
      total += list.ids[i];
    }
  }
  return total;
}

bool parse_range(char **p, int64_t *start, int64_t *end) {

  while (**p == ',' || **p == ' ' || **p == '\n' || **p == '\t')
    (*p)++;

  // duck out if \0
  if (!**p) {
    return false;
  }
  char *endptr;

  *start = strtoll(*p, &endptr, 10);

  // duck out if nothing more to look at
  if (*p == endptr) {
    return false;
  }

  *p = endptr;

  if (**p != '-') {
    return false;
  }
  (*p)++;

  *end = strtoll(*p, &endptr, 10);
  if (*p == endptr) {
    return false;
  }
  *p = endptr;
  return true;
}
