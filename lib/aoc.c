#include "aoc.h"
#include "assert.h"

id_list id_list_create(int max_digits);
void id_list_free(id_list list);

id_list id_list_create(int max_digits) {
  assert(max_digits >= 1 && max_digits <= 9);
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
  for (int64_t mult = 10; mult <= size; mult *= 10) {
    for (int64_t chunk = mult / 10; chunk <= mult - 1; chunk++) {
      ids[n++] = chunk * mult + chunk;
    }
  }

  return (id_list){.ids = ids, .count = n};
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
