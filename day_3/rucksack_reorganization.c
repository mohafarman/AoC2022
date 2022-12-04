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
	// Using struct to "return" multiple variables from a func
	Compartments compartments;
	int mid, i, k;

	compartments.length = strlen(list);
	mid = compartments.length / 2;

	for (i = 0; i < mid; i++) {
		compartments._1[i] = list[i];
	}
	// End of line, C style strings
	compartments._1[i] = '\0';

	// Start from the mid and work towards end of string
	for (i = mid, k = 0; i <= compartments.length; i++, k++) {
		compartments._2[k] = list[i];
	}

	return compartments;
}

void compare_compartments(char comp_1[BUFFER], char comp_2[BUFFER], int length) {
	int i = 0, k, ascii, half_length;

	half_length = length;

	for (i = 0; i < length; i++) {
		for (k = 0; k < length; k++) {
			if (comp_1[i] == comp_2[k]) {
				//printf("Comp 1: %c\tCompt 2: %c\n", comp_1[i], comp_2[k]);
				if (isupper(comp_1[i])) {	// A - Z
					ascii = comp_1[i] - 'A'+27;
				} 
				else {						// a - z 
					ascii = comp_1[i] - 'a'+1;
				}
				points += ascii;
				//printf("%c has value %d\n", comp_1[i], ascii);
				//printf("%c\n", comp_1[i]);
				return;
			}
		}
	}
}

int main() {
	Compartments compartments;
	int rucksack = 0;
	char filename[8] = "input";
	FILE *file = fopen(filename, "r");

	char buffer[BUFFER];

	while (fgets(buffer, sizeof(buffer), file)) {
		//printf("----------\nRucksack #%d\n", rucksack);
		compartments = split_into_compartments(buffer);

		compare_compartments(compartments._1, compartments._2, compartments.length);
		rucksack++;

	}

	//printf("\n");
	printf("Total sum: %d\n", points);

	return 0;
}
