#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int points = 0;
int points_all_overlap = 0;

void
check_full_overlap(char *sections[4]) {
	// Check if first section is within the second section
	if ((atoi(sections[0]) >= atoi(sections[2]) && (atoi(sections[1]) <= atoi(sections[3])))) {
		points++;
	}
	// Check if second section is within the first section
	else if ((atoi(sections[2]) >= atoi(sections[0]) && (atoi(sections[3]) <= atoi(sections[1])))) {
		points++;
	}
}

void
check_all_overlap(char *sections[4]) {
	// Check if first section is within the second section
	if ((atoi(sections[0]) >= atoi(sections[2]) && (atoi(sections[1]) <= atoi(sections[3])))) {
		points_all_overlap++;
	}
	// Check if second section is within the first section
	else if ((atoi(sections[2]) >= atoi(sections[0]) && (atoi(sections[3]) <= atoi(sections[1])))) {
		points_all_overlap++;
	}
	// Check if first number in first section overlaps with the
	// last number in the second section
	else if ((atoi(sections[0]) <= atoi(sections[3])) && (atoi(sections[1]) >= atoi(sections[3]))) {
		points_all_overlap++;
	}
	// Check if second number in first section overlaps with the
	// first number in the second section
	else if (atoi(sections[1]) >= atoi(sections[2]) && (atoi(sections[1]) <= atoi(sections[3]))) {
		points_all_overlap++;
	}
}

void
parse_line(char *line, char *sections[4]) {
	const char *delim = "-,";
	char *token;
	int count = 0;
	token = strtok(line, delim);

	while (token) {
		sections[count++] = token;
		token = strtok(NULL, delim);
	}
}

int main(int argc, char **argv) {

	if (argc < 2) {
		fprintf(stderr, "Input file not specified.\n");
		exit(1);
	}

	FILE *file = fopen(argv[1], "r");
	if (!file) {
		fprintf(stderr, "File could not be read.\n");
		exit(1);
	}

	char buffer[15];
	char *sections[4];

	while (fgets(buffer, 15, file) != NULL) {
		parse_line(buffer, sections);
		check_full_overlap(sections);
		check_all_overlap(sections);
	}

	printf("Result part 1: %d\n", points);
	printf("Result part 2: %d\n", points_all_overlap);
	return 0;
}
