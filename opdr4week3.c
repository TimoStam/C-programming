#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct teamlid {
    int id;
    char name[20];
    char education[10];
};


int main(){
    struct teamlid *team;
    int memberCount;
    char edu[10];
    printf("How many members: ");
    scanf("%d", &memberCount);
    team = (struct teamlid *)malloc(memberCount * sizeof(struct teamlid));
    if (team == NULL){
        printf("Failed to allocate memory");
        return 1;
    }
    for (int i = 0; i < memberCount; i++){
        team[i].id = i + 1;
        printf("Player name: ");
        scanf(" %19[^\n]", team[i].name);
        printf("Player education: ");
        scanf(" %9[^\n]", team[i].education);
    }

    printf("Which education: ");
    scanf(" %9[^\n]", edu);
    for (int i = 0; i < memberCount; i++){
        if (strcmp(edu, team[i].education) == 0){
            printf("Name: %s ", team[i].name);
            printf("Id: %d ", team[i].id);
            printf("Education: %s\n", team[i].education);
        }
    }
}