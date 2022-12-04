#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define BUFFER 100
#define BADGE_SIZE 3

typedef struct badge_s {
	char elf1[BUFFER];
	char elf2[BUFFER];
	char elf3[BUFFER];
} badge_s; 

void
badge_find(const char *elf1, const char *elf2, const char *elf3) {
	printf("Elf 1: %sElf 2: %sElf 3: %s\n", elf1, elf2, elf3);

	/*
	 * Maybe solution here:
	 * https://www.geeksforgeeks.org/common-characters-n-strings/
	 */
}

int points = 0;

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
