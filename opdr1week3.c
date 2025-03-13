#include <stdio.h>

void printArray(double* numberArr, int size){
    printf("{");
    for (int i =0; i < size-1; i++){
        printf("%.2f, ", numberArr[i]);
    }
    printf("%.2f}\n", numberArr[size-1]);
}


int main(){
    double numbers1[] = {5.89, 6.20, -2.13};
    double numbers2[] = {3.14};
    printArray(numbers1, (sizeof(numbers1)/sizeof(double)));
    
}