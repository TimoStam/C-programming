#include <stdio.h>

int main(){
    char buf[20];
    scanf("%19s", buf);

    for (int i = 0; i < sizeof(buf)/sizeof(buf[0]); i++){
        printf("%c", buf[i]);
    }
    printf("\n");
    return 1;
}