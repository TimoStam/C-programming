#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateArray(int low, int high, int size){
    srand(time(NULL));
    int r = 0;
    int *p1 = malloc(size * sizeof *p1);
    int *p2 = malloc(size * sizeof *p2);

    if (p1 == NULL){
        printf("Failed to allocate memory");
        return;
    }

    if (p2 == NULL){
        printf("Failed to allocate memory");
        return;
    }

    for (int i = 0; i < size; i++){
        r = rand() % (high - low + 1) + low;
        p1[i] = r;
    }

    for (int i = 0; i < size; i++){
        r = rand() % (high - low + 1) + low;
        p2[i] = r;
    }

    for (int i = 0; i < size; i++){
        printf("%d ", p1[i]);
    }
    printf("\n");
    for (int i = 0; i < size; i++){
        printf("%d ", p2[i]);
    }
    printf("\n");
    
    free(p1);
    free(p2);
    return;
}

int main(){
    int lower = 0;
    int higher = 0;
    int size = 0;
    scanf("%d %d %d", &lower, &higher, &size);
    generateArray(lower, higher, size);
}