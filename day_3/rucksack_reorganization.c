#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define BUFFER 100

typedef struct Compartments {
	char _1[BUFFER];	// First compartment
	char _2[BUFFER];	// Second compartment
	int length;
} Compartments; 

int points = 0;

/*
 * Solution thanks to https://btechgeeks.com/c-program-to-divide-a-string-into-two-equal-strings/
 */
Compartments split_into_compartments(char list[BUFFER]) {
	/* Function to split input buffer and return two seperate buffers
	 * Using struct to "return" multiple variables from a func */

	Compartments compartments;
	int mid, i, k;

	compartments.length = strlen(list);
	mid = compartments.length / 2;

	for (i = 0; i < mid + 1; i++) {
		compartments._1[i] = list[i];
	}
	// End of line, C style strings
	compartments._1[i] = '\0';

	// Start from the mid and work towards end of string
	for (i = mid, k = 0; i <= compartments.length + 1; i++, k++) {
		compartments._2[k] = list[i];
	}

	return compartments;
}

void compare_compartments(char comp_1[BUFFER], char comp_2[BUFFER], int length) {
	/* Function to compare the two buffers */

	int i = 0, k, ascii, half_length;

	/*
	 * Solution from https://github.com/6rian/practice-c/blob/main/advent-of-code-2022/day3/day3.c
	 * strcspn = string compare span
	 * Return position of character that is not found in the other string
	 */
	size_t loc = strcspn(comp_1, comp_2);	// Compare strings
	char item = comp_1[loc];

	if (isupper(item)) {	// A - Z
		ascii = item - 'A'+27;
	} 
	else {						// a - z 
		ascii = item - 'a'+1;
	}

	points += ascii;
}

int main() {
	Compartments compartments;
	char filename[8] = "input";
	FILE *file = fopen(filename, "r");
	char buffer[BUFFER];

	while (fgets(buffer, sizeof(buffer), file)) {
		compartments = split_into_compartments(buffer);

		compare_compartments(compartments._1, compartments._2, compartments.length);

	}
	fclose(file);

	printf("Total sum: %d\n", points);
	return 0;
}
