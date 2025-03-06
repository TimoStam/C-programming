#include <stdio.h>

int firstThrow(int pins[], int score){
    printf("Throw 1, Enter the amount of knocked down pins: ");
    scanf_s("%d", &pins[0]);
    if (pins[0] > 10 || pins[0] < 0){
        printf("Invalid input.\n");
        return -1;
    }
    if (pins[0] == 10){
        printf("Strike!\n");
        return score + 10;
    }
    return score + pins[0];
}

int secondThrow(int pins[], int score){
    printf("Throw 2, Enter the amount of knocked down pins: ");
    scanf_s("%d", &pins[1]);
    if (pins[1] > 10 || pins[1] < 0){
        printf("Invalid input.\n");
        return -1;
    }
    if (pins[0] + pins[1] > 10){
        printf("Invalid input.\n");
        return -1;
    }
    if (pins[0] + pins[1] == 10){
        printf("Spare!\n");
        return score + 10;
    }
    return score + pins[1];
}

int extraThrow(int score){
    int extraPins;
    printf("Extra throw, Enter the amount of knocked down pins: ");
    scanf_s("%d", &extraPins);
    if (extraPins > 10 || extraPins < 0){
        printf("Invalid input.\n");
        return -1;
    }
    return score + extraPins;
}

int main(){
    int turns = 0;
    int pins[2];
    int score = 0;
    int strikeBonus = 0;
    int spareBonus = 0;
    int extraPins1 = 0, extraPins2 = 0;

    for (turns = 0; turns < 10; turns++){
        score = firstThrow(pins, score);
        if (score == -1){
            return 0;
        }
        if (pins[0] == 10){
            strikeBonus += 2;
        } else {
            score = secondThrow(pins, score);
            if (score == -1){
                return 0;
            }
            if (pins[0] + pins[1] == 10){
                spareBonus += 1;
            }
        }

        if (strikeBonus > 0){
            score += pins[0];
            strikeBonus--;
        }
        if (spareBonus > 0){
            score += pins[0];
            spareBonus--;
        }
    }

    // Handle the last turn extra throws
    if (pins[0] == 10 || pins[0] + pins[1] == 10){
        printf("Extra throw 1, Enter the amount of knocked down pins: ");
        scanf_s("%d", &extraPins1);
        if (extraPins1 > 10 || extraPins1 < 0){
            printf("Invalid input.\n");
            return 0;
        }
        score += extraPins1;

        if (pins[0] == 10 || pins[0] + pins[1] == 10){
            printf("Extra throw 2, Enter the amount of knocked down pins: ");
            scanf_s("%d", &extraPins2);
            if (extraPins2 > 10 || extraPins2 < 0){
                printf("Invalid input.\n");
                return 0;
            }
            score += extraPins2;
        }
    }

    printf("Final Score: %d\n", score);
    return 0;
}