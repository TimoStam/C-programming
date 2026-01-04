#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char namen1[3][8]= {"Jan", "Piet", "Klaas"};
    char *namen2[]={"Jan", "Piet", "Klaas"};
    strcpy(namen1[1], "Hansje");
    for (int i = 0; i<sizeof(namen1)/sizeof(namen1[0]); i++){
        printf("%s ", namen1[i]);
    }
    printf("\n");
    namen2[1] = "Hansje";
    for (int i = 0; i<sizeof(namen2)/sizeof(namen2[0]); i++){
        printf("%s ", namen2[i]);
    }

}