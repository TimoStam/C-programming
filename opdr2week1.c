#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int grens(void);

static void clear_input_buffer() {
	while (getchar() != '\n');
}

int main(void) {
	int value = grens();
	int guess[5] = { 0,0,0,0,0 };
	int currentGuess;
	for (int i = 0; i < (sizeof(guess) / sizeof(guess[0])); ++i) {
		while (scanf_s("%d", &currentGuess) != 1) {
			printf("ongeldige invoer");
			clear_input_buffer();
		}
		guess[i] = currentGuess;
		if (currentGuess == value) {
			printf("Correct\n");
			printf("%d\n", value);
			for (int j = 0; j < sizeof(guess) / sizeof(guess[0]); ++j) {
				printf("%d ", guess[j]);
			}
			return 0;
		}
		else {
			printf("Try again.\n");
			clear_input_buffer();
		}

	}
	printf("You failed\n");
	printf("%d\n", value);
	for (int j = 0; j < sizeof(guess) / sizeof(guess[0]); ++j){
		printf("%d ", guess[j]);
	}

	return 0;

}

static int grens(void) {
	srand((unsigned int)(time(NULL)));
	int ondergrens = 0;
	int bovengrens = 0;
	printf("Vul een ondergrens in: \n");
	while (scanf_s("%d", &ondergrens) != 1) {
		printf("ongeldige invoer");
		clear_input_buffer();
	}
	printf("Vul een bovengrens in: \n");
	while (scanf_s("%d", &bovengrens) != 1) {
		printf("ongeldige invoer");
		clear_input_buffer();
	}
	if (bovengrens <= ondergrens) {
		printf("Ongeldige invoer");
		clear_input_buffer();
	}
	int number = (rand() % (bovengrens - ondergrens + 1)) + ondergrens;
	return number;
}
