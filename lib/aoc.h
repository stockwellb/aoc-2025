#ifndef AOC_H
#define AOC_H

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int64_t *ids;
  int count;
} id_list;

id_list id_list_create(int max_digits);
void id_list_free(id_list list);
int64_t sum_ids_in_range(id_list list, int64_t start, int64_t end);
bool parse_range(char **p, int64_t *start, int64_t *end);

#endif
