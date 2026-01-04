#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUES 20

float FtoC(float fahrenheit){
    return (fahrenheit - 32)*5/9;
}

float VtoC(float voltage){
    return (voltage*20)-20;
}

void copyWithConversion(float data[], int size, float (*FtoC)(float)){
    for (int i = 0; i<MAX_VALUES; i++){
        printf("original data: %.2f, ", data[i]);
        data[i] = FtoC(data[i]);
        printf("converted data: %.2f\n", data[i]);
    }
}

void fileToArray(){
    FILE *file1;
    FILE *file2;
    file1 = fopen("C:\\Users\\timos\\Documents\\C programming\\fahrenheit.txt", "r");
    file2 = fopen("C:\\Users\\timos\\Documents\\C programming\\voltage.txt", "r");
    float fahrenheit[MAX_VALUES];
    float voltage[MAX_VALUES];
    int count = 0;
    while(count < MAX_VALUES && fscanf(file1, "%f", &fahrenheit[count]) == 1){
        count++;
    }
    while(count < MAX_VALUES && fscanf(file2, "%f", &voltage[count]) == 1){
        count++;
    }
    copyWithConversion(fahrenheit, sizeof(fahrenheit), FtoC);

    fclose(file1);
    fclose(file2);
}

int main(){

    fileToArray();
    return 0;
}