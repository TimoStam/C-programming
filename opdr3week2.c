#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 20

int main() { 
    char buffer[MAX_LENGTH + 2];
    char key[MAX_LENGTH];
    char value[MAX_LENGTH]; 
    int input = 0;

    const char *fuels[] = {"benzine", "diesel", "LPG", "kerosine"};
    int num_fuels = 4;

    while (!input) {
        printf("Stuur een key en een value die gesplitst zijn door een ':': ");
        fgets(buffer, sizeof(buffer), stdin);
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        if (strlen(buffer) > MAX_LENGTH) {
            printf("Teveel characters, het limiet is %d.\n", MAX_LENGTH);
        } else {
            if (sscanf(buffer, "%[^:]: %s", key, value) == 2) {
                if (strcmp(key, "Brandstof") == 0) {
                    int valid = 0;
                    for (int i = 0; i < num_fuels; i++) {
                        if (strcmp(value, fuels[i]) == 0) {
                            valid = 1;
                            break;
                        }
                    }
                    if (valid) {
                        printf("Key: %s, Brandstof: %s\n", key, value);
                        input = 1;
                    } else {
                        printf("Ongeldige brandstof: %s. Toegestane waardes: benzine, diesel, LPG, kerosine.\n", value);
                    }
                } 
                else {
                    int numericValue;
                    if (sscanf(value, "%d", &numericValue) == 1) {
                        printf("Key: %s, Value: %d\n", key, numericValue);
                        input = 1;
                    } else {
                        printf("Foute invoer, probeer opnieuw.\n");
                    }
                }
            } else {
                printf("Foute invoer, probeer opnieuw.\n");
            }
        }
    }
    return 0;
}
