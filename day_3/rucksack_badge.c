#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER 100
#define BADGE_SIZE 3
#define MAX_CHAR 52		// small + big chars

typedef struct badge_s {
	char elf1[BUFFER];
	char elf2[BUFFER];
	char elf3[BUFFER];
} badge_s; 

int points = 0;

void
badge_find(char *elf1, char *elf2, char *elf3) {
	/* 
	 * Inspired by this solution:
	 * https://github.com/Lewisjohnward/C/blob/main/AoC/03rucksack/part2.c
	 */

	char *arr[] = {elf1, elf2, elf3};
	char buf[BUFFER], buf2[BUFFER];
	memset(buf, 0, BUFFER);
	memset(buf2, 0, BUFFER);
	char *ptr;
	ptr = buf;

	for (int i = 0; i < strlen(arr[0]) - 1; i++) {
		for (int k = 0; k < strlen(arr[1]) - 1; k++) {
			if (arr[0][i] == arr[1][k]) {
				*ptr++ = arr[0][i];
				*ptr = '\0';
			}
		}
	}

	// Now buf contains common chars between arr[0] and arr[1]
	// Thus use a different buffer to store common char
	ptr = buf2;

	// Compare buf to last string in badge
	for (int i = 0; buf[i]; i++) {
		for (int k = 0; k < strlen(arr[2]) - 1; k++) {
			if (buf[i] == arr[2][k]) {
				//printf("Common char: %c\n", arr[2][k]);
				*ptr++ = arr[2][k];
				*ptr = '\0';
			}
		}
	}

	if (buf2[0] < 91) {
		points += buf2[0] - 'A' + 27;
		printf("Upper : %c - Points : %d\n", buf2[0], buf2[0] - 38);
	}
	else {
		points += buf2[0] - 'a' + 1;
		printf("Lower : %c - Points : %d\n", buf2[0], buf2[0] - 'a' + 1);
	}
}

int main() {
	char filename[8] = "input";
	FILE *file = fopen(filename, "r");
	char buffer[BUFFER];
	char group[BADGE_SIZE][BUFFER];
	int count = 0, i;

	char *str1 = NULL, *str2 = NULL, *str3 = NULL;

	while (fgets(buffer, sizeof(buffer), file)) {
		strncpy(group[count++], buffer, BUFFER);

		if (count == 3) {
			badge_find(group[0], group[1], group[2]);
			count = 0;

			for (i = 0; i < BADGE_SIZE; i++) {
				memset(group[i], 0, sizeof(group[i]));
			}
		}
	}

	fclose(file);

	printf("Total sum: %d\n", points);
	return 0;
}
