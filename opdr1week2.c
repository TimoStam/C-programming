#include <stdio.h>

void copyString(char *source, char *dest){
    while (*source != '\0'){
        *dest = *source;
        source++;
        dest++;
    }
    *dest = '\0';
}

int main(){
    char sourceArr[] = "Hello, World!";
    char destArr[50];
    copyString(sourceArr, destArr);
    printf("%s\n", destArr);
    return 0;
}