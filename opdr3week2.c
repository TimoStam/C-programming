#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 20

int main(){
    char buffer[MAX_LENGTH + 2];
    char key[MAX_LENGTH];
    int value;

    printf("Stuur een key en een value die gesplitst zijn door een ':': ");
    fgets(buffer, sizeof(buffer), stdin);
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }
    if (strlen(buffer) > MAX_LENGTH) {
        printf("Teveel characters, het limiet is %d.\n", MAX_LENGTH);
    } else {
        if (sscanf(buffer, "%[^:]: %d", key, &value) == 2) {
            printf("Key: %s, Value: %d\n", key, value);
        } else {
            printf("Invalid input format.\n");
        }
    }

    return 0;
}