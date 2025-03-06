#include <stdio.h>
#define MAX_LENGTH 20

int main(){
    char buffer[MAX_LENGTH + 2];
    printf("stuur iets: ");
    fgets(buffer, sizeof(buffer), stdin);
    printf("je hebt gestuurd: %s\n", buffer);
    return 0;
}