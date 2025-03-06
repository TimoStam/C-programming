#include <stdio.h>


#define MAX_MATCHES 36
#define MAX_NAME 50

typedef struct {
    char location[5];
    int homeScore;
    int awayScore;
    int opponent[MAX_NAME];
} Match;


int main(){
    FILE *file = fopen("matches.txt", "r");
    Match matches[MAX_MATCHES];
    int matchCount = 0;
    if (file == NULL) {
        printf("File not found\n");
        return 1;
    } else {
        while (fscanf(file, "%s %d %d %s", 
            matches[matchCount].location, 
            &matches[matchCount].homeScore, 
            &matches[matchCount].awayScore, 
            matches[matchCount].opponent) == 4) {
            matchCount++;
            if (matchCount >= MAX_MATCHES) {
                break;
            }
        }
        fclose(file);
    }
}