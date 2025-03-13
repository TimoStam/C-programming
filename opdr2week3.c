#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateArray(int low, int high, int size){
    srand(time(NULL));
    int r = 0;
    int *p1 = malloc(size * sizeof *p1);

    if (p1 == NULL){
        printf("Failed to allocate memory");
        return;
    }
    for (int i = 0; i < size; i++){
        r = rand() % (high - low + 1) + low;
        p1[i] = r;
        printf("%d ", p1[i]);
    }
    printf("\n");
    free(p1);
    return;
}

int main(){
    int lower = 0;
    int higher = 0;
    int size = 0;
    scanf("%d %d %d", &lower, &higher, &size);
    generateArray(lower, higher, size);
}