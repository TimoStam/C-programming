#include <stdio.h>


void copyString(char *source, char *dest, int sourceSize, int destSize){
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
    char sourceArr[] = "Hello, World!";
    char destArr[10];
    copyString(sourceArr, destArr, sizeof(sourceArr), sizeof(destArr));
    printf("%s\n", destArr);
    return 0;
}