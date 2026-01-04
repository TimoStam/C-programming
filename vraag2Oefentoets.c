#include <stdio.h>
#include <stdlib.h>

int get_invoer_gebruiker(){
    int buf = 0;
    scanf("%d", &buf);
    return buf;
}

int main(){
    printf("Vul het aantal rijen in\n");
    int aantal_rijen = get_invoer_gebruiker();
    printf("Vul het aantal kolommen in\n");
    int aantal_kolommen = get_invoer_gebruiker();

    int table[aantal_rijen][aantal_kolommen];
    for (int row = 0; row<aantal_rijen; row++){
        for(int col = 0; col<aantal_kolommen; col++){
            table[row][col] = 1;
            printf("%d ", table[row][col]);
        }
        printf("\n");
    }    return 0;
}