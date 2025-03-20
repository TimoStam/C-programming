#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateArrays(int low, int high, int size, int* p1, int* p2){
    srand(time(NULL));

    for (int i = 0; i < size; i++){
        p1[i] = rand() % (high - low + 1) + low;
    }
    
    for (int i = 0; i< size; i++){
        p2[i] = rand() % (high - low + 1) + low;
    

void printArray(int size, int* p1, int* p2){

    for (int i = 0; i < size; i++){
        printf("%d ", p1[i]);
    }
    printf("\n");

    for (int i = 0; i < size; i++){
        printf("%d ", p2[i]);
    }
    printf("\n");
}

void printHighest(int size, int* p1, int* p2){
    for (int i = 0; i < size; i++){
        if (p1[i]>p2[i]){
            printf("index: %d highest number is %d\n",i, p1[i]);
        } else if (p2[i]>p1[i]){
            printf("index: %d highest number is %d\n",i, p2[i]);
        } else {
            printf("index: %d The values are equal: %d\n",i, p1[i]);
        }
    }
}

int main(){
    int lower, higher;
    int size = 0;
    int *p1 = malloc(size * sizeof *p1);
    int *p2 = malloc(size * sizeof *p2);
    if (p1 == NULL || p2 == NULL){
        printf("Incorrect memory allocation");
        return 1;
    }
    scanf("%d %d %d", &lower, &higher, &size);
    generateArrays(lower, higher, size, p1, p2);
    printArray(size, p1, p2);
    printHighest(size, p1, p2);
    free(p1);
    free(p2);
}