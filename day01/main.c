#include <stdio.h>
#include "../lib/aoc.h"

int main(int argc, char **argv) {
	const char *filename = argc > 1 ? argv[1] : "input.txt";
	printf("Advent of Code 2025 - Day 01\n");
	printf("Using input: %s\n", filename);

	// StringArray lines = read_lines(filename);
	// for (size_t i = 0; i < lines.count; i++) {
	//     printf("%s\n", lines.items[i]);
	// }
	// free_lines(&lines);

	return 0;
}
