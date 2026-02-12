#include <stdio.h>

void printArray(const double numberArr[], size_t size){
    printf("{");
    for (int i =0; i < size-1; i++){
        printf("%.2f, ", numberArr[i]);
    }
    printf("%.2f}\n", numberArr[size-1]);
}


int main(){
    double numbers[] = {5.89, 6.20, -2.13};
    // double numbers[] = {3.14};
    printArray(numbers, (sizeof(numbers)/sizeof(numbers[0])));
}