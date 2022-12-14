#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_MAX 1000

int points = 0;

void
check_overlap(char *sections[4]) {
	// Partial overlap
	//if ((atoi(sections[1]) >= atoi(sections[2]))) {
	//	printf("%s-%s, %s-%s\n", sections[0], sections[1],sections[2],sections[3]);
	//}

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

int main(int argc, char **argv[]) {

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
	int count = 0;

	while (fgets(buffer, 15, file) != NULL) {
		parse_line(buffer, sections);
		check_overlap(sections);
	}

	printf("Result: %d\n", points);
	return 0;
}
