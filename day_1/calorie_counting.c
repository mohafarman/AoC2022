#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_BYTES 8

const char *filename = "input_calorie_counting";
FILE *file;

int main() {

	char line[MAX_LINE_BYTES];
	int total_calories, index = 0, array_total_cal[2000];
	int i, highest_tot_cal = 0, top_three_tot_cal[3];

	file = fopen(filename, "r");

	if (!file) { 
		fprintf(stderr, "Error opening file %s\n", filename);
		return 1;
   	}

	while (fgets(line, MAX_LINE_BYTES, file)) {
		if (strcmp(line, "\n") == 0) {
			array_total_cal[index] = total_calories;
			index++;
			total_calories = 0;
		}
		else {
			total_calories += atoi(line);
		}
	}
	fclose(file);

	for (i = 0; i < index; i++) {
		if (array_total_cal[i] > top_three_tot_cal[0]) {
			top_three_tot_cal[0] = array_total_cal[i];
		}
		else if (array_total_cal[i] < top_three_tot_cal[0] && array_total_cal[i] > top_three_tot_cal[1]) {
			top_three_tot_cal[1] = array_total_cal[i];
		}
		else if (array_total_cal[i] < top_three_tot_cal[0] && array_total_cal[i] < top_three_tot_cal[1] && array_total_cal[i] > top_three_tot_cal[2]) {
			top_three_tot_cal[2] = array_total_cal[i];
		}
	}

	printf("Top three elfs carrying highest calories are: \nElf 1: %d\nElf 2: %d\nElf 3: %d\n", top_three_tot_cal[0], top_three_tot_cal[1], top_three_tot_cal[2]);

	printf("The total amounts to: %d\n", top_three_tot_cal[0] + top_three_tot_cal[1] + top_three_tot_cal[2]);

	return 0;
}
