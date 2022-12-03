#include <stdio.h>
#include <string.h>

enum GamePoints {
	Rock = 1,	// Rock
	Paper = 2,	// Paper
	Scissors = 3,	// Scissors
	Lost = 0,
	Draw = 3,
	Won = 6
};

// O = Opponent
#define O_Rock "A"
#define O_Paper "B"
#define O_Scissors "C"

// P = Proponent
#define P_Rock "X"
#define P_Paper "Y"
#define P_Scissors "Z"

// O = Outcome
#define O_Lose "X"
#define O_Draw "Y"
#define O_Win "Z"

int hands = 3, points;	// Hands = choices in the game

void part_2(char *opponent, char *outcome) {

	// Outcome has to be a win
	if (strcmp(outcome, O_Win) == 0) {
		points += Won;
		if (strcmp(opponent, O_Rock) == 0) {	// Opponent choses Rock
			points += Paper;
		}
		else if (strcmp(opponent, O_Paper) == 0) {	// Opponent choses Rock
			points += Scissors;
		}
		else {
			points += Rock;
		}
		return;
	}

	// Outcome has to be a draw
	if (strcmp(outcome, O_Draw) == 0) {
		points += Draw;
		if (strcmp(opponent, O_Rock) == 0) {	// Opponent choses Rock
			points += Rock;
		}
		else if (strcmp(opponent, O_Paper) == 0) {	// Opponent choses Rock
			points += Paper;
		}
		else {
			points += Scissors;
		}
		return;
	}

	// Outcome has to be a loss
	if (strcmp(outcome, O_Lose) == 0) {
		points += Lost;	// 0
		if (strcmp(opponent, O_Rock) == 0) {	// Opponent choses Rock
			points += Scissors;
		}
		else if (strcmp(opponent, O_Paper) == 0) {	// Opponent choses Rock
			points += Rock;
		}
		else {
			points += Paper;
		}
		return;
	}
}

int main() {

	const char *filename = "input";
	FILE *file = fopen(filename, "r");
	
	if (!file) { 
		fprintf(stderr, "Error opening file %s\n", filename);
		return 1;
   	}

	char line[8];
	char delim_space[] = " ", delim_new_row[] = "\n";
	char *opponent, *proponent;
	int flag = 0;
	while (fgets(line, 8, file)) {
		flag++;
		opponent = strtok(line, delim_space);
		proponent = strtok(NULL, delim_new_row);

		part_2(opponent, proponent);
	}

	printf("Total points: %d\n", points);

	return 0;
}
