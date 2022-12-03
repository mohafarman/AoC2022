#include <stdio.h>
#include <string.h>

/* A for Rock, B for Paper, and C for Scissors.
 * X for Rock, Y for Paper, and Z for Scissors.
 * 
 * 1 for Rock, 2 for Paper, and 3 for Scissors.
 * 0 if you lost, 3 if the round was a draw, and 6 if you won.
 */

enum GamePoints {
	Rock = 1,	// Rock
	Paper = 2,	// Paper
	Scissors = 3,	// Scissors
	Lost = 0,
	Draw = 3,
	Won = 6
};

#define O_Rock "A"
#define O_Paper "B"
#define O_Scissors "C"
#define P_Rock "X"
#define P_Paper "Y"
#define P_Scissors "Z"

#define O_Lose "X"
#define O_Draw "Y"
#define O_Win "Z"

int hands = 3, points;

void part_1(char *opponent, char *proponent) {
	// Check for win and give points.
	if (
		(strcmp(proponent, P_Rock) == 0) 		// Rock
		&& (strcmp(opponent, O_Scissors) == 0)	// Scissors
	   ) {
		points += Won;
	}
	else if (
		(strcmp(proponent, P_Paper) == 0) 		// Paper
		&& (strcmp(opponent, O_Rock) == 0)		// Rock
		) {
		points += Won;
	}
	else if (
		(strcmp(proponent, P_Scissors) == 0) 	// Scissors
		&& (strcmp(opponent, O_Paper) == 0)		// Paper
		) {
		points += Won;
	}

	// Check for draw and give points.
	if (
		(strcmp(proponent, P_Rock) == 0)		// Rock
		&& (strcmp(opponent, O_Rock) == 0)
		) {
		points += Draw;
	}

	else if (
		(strcmp(proponent, P_Paper) == 0)		// Paper
		&& (strcmp(opponent, O_Paper) == 0)
		) {
		points += Draw;
	}

	else if (
		(strcmp(proponent, P_Scissors) == 0)	// Scissors
		&& (strcmp(opponent, O_Scissors) == 0)
		) {
		points += Draw;
	}
}

void point_for_hand(char *opponent, char *proponent) {
	// Give points for hand
	if (strcmp(proponent, P_Rock) == 0) {	// Rock
		points += Rock;
	}

	else if (strcmp(proponent, P_Paper) == 0) {	// Paper
		points += Paper;
	}

	else {										// Scissor
		points += Scissors;
	}
}

int main() {

	//const char *filename = "input_rock_paper_scissors";
	const char *filename = "input";
	FILE *file = fopen(filename, "r");
	
	if (!file) { 
		fprintf(stderr, "Error opening file %s\n", filename);
		return 1;
   	}

	char line[8];
	char delim_space[] = " ", delim_new_row[] = "\n";
	char *opponent, *proponent;
	while (fgets(line, 8, file)) {
		opponent = strtok(line, delim_space);
		proponent = strtok(NULL, delim_new_row);

		point_for_hand(opponent, proponent);
		part_1(opponent, proponent);
	}

	printf("Total points: %d\n", points);

	return 0;
}
