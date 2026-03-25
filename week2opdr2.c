#include <stdio.h>


void copyString(char *source, char *dest, size_t sourceSize, int destSize){
    if (sourceSize > destSize){
        printf("Source string is too large.\n");
        *dest = '\0';
        return;
    }
    while (*source != '\0'){
        *dest = *source;
        source++;
        dest++;
    }
    *dest = '\0';
}

int main(){
    char sourceArr[50] = "Hello World!";
    char destArr[20];
    size_t string_size = 0;
    for (int i = 0; i < sizeof(sourceArr); i++){
        if (sourceArr[i] != '\0'){
            string_size++;
        }
    }
    copyString(sourceArr, destArr, string_size, sizeof(destArr));
    printf("%s\n", destArr);
    return 0;
}