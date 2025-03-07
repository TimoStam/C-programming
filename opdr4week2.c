#include <stdio.h>
#include <string.h>
#define MAX_MATCHES 36
typedef struct{
    char isHome[5];
    int ownScore;
    int opponentScore;
    char opponent[10];
}Match;

typedef struct{
    int points;
    int matchesPlayed;
    int goalsFor;
    int goalsAgainst;
}Result;

int main(){
    FILE *file;
    Match matches[MAX_MATCHES];
    Result results;
    char name[10];
    int matchCount = 0;
    file = fopen("C:\\Users\\timos\\Documents\\CP\\C-programming\\test.txt", "r");
    if (file == NULL){
        printf("file didn't open\n");
    }
    while(matchCount < MAX_MATCHES && fscanf(file, "%s %d - %d %s", 
        matches[matchCount].isHome, 
        &matches[matchCount].ownScore, 
        &matches[matchCount].opponentScore, 
        matches[matchCount].opponent) == 4){
        printf("%s %d - %d %s \n", matches[matchCount].isHome, matches[matchCount].ownScore, matches[matchCount].opponentScore, matches[matchCount].opponent);
        matchCount++;
    }
    for (int i = 0; i<matchCount; i++){
        printf("Tegenstander: %s\n", matches[i].opponent);
    }
    results.matchesPlayed = matchCount;
    results.points = 0;
    for (int i = 0; i < matchCount; i++){
        results.goalsFor += matches[i].ownScore;
        results.goalsAgainst += matches[i].opponentScore;
        if (matches[i].ownScore > matches[i].opponentScore){
            results.points += 3;
        } else if (matches[i].ownScore == matches[i].opponentScore){
            results.points += 1;
        }
    }
    printf("Matches played: %d, %d points and %d - %d goal difference\n", results.matchesPlayed, results.points, results.goalsFor, results.goalsAgainst);
    printf("Opponent name: ");
    if (scanf("%9s", name) != 1){
        printf("Invalid input\n");
    }
    for (int i = 0; i< matchCount; i++){
        if (strcmp(matches[i].opponent, name) == 0){
            if (matches[i].ownScore > matches[i].opponentScore){
                printf("Won against %s", matches[i].opponent);
            } else if (matches[i].ownScore == matches[i].opponentScore){
                printf("Tied against %s", matches[i].opponent);
            } else {
                printf("Lost against %s", matches[i].opponent);
            }
        }
    }

    fclose(file);
}