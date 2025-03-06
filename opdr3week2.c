#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 20

int main(){
    char buffer[MAX_LENGTH + 2];
    printf("stuur iets: ");
    fgets(buffer, sizeof(buffer), stdin);
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }

    // Check if input length exceeds MAX_LENGTH
    if (strlen(buffer) > MAX_LENGTH) {
        printf("Input exceeds maximum length of %d characters.\n", MAX_LENGTH);
    } else {
        printf("je hebt gestuurd: %s\n", buffer);
    }

    return 0;
}