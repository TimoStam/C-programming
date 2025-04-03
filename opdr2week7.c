#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUES 20

float fahrenheitToCelsius(float fahrenheit){
    return (fahrenheit - 32)*5/9;
    return 0;
}

float voltageToCelsius(float voltage){
    return (voltage*20)-20;
}

void copyWithConversion(float data[], int size, float (*conversion)(float)){
    for (int i =0; i<size; i++){
        printf("data: %.2f, converted: %.2f\n", data[i], conversion(data[i]));
    }
}
int main(){
    FILE *file1;
    FILE *file2;
    file1 = fopen("C:\\Users\\timos\\Documents\\C programming\\fahrenheit.txt", "r");
    file2 = fopen("C:\\Users\\timos\\Documents\\C programming\\voltage.txt", "r");
    float fdata[MAX_VALUES];
    float vdata[MAX_VALUES];
    int count = 0;
    while (count<MAX_VALUES && fscanf(file1, "%f", &fdata[count]) == 1){
        count++;
    }
    count = 0;
    while (count<MAX_VALUES && fscanf(file2, "%f", &vdata[count]) == 1){
        count++;
    }
    fclose(file1);
    fclose(file2);
    printf("Fahrenheit to celsius conversion: \n");
    copyWithConversion(fdata, MAX_VALUES, fahrenheitToCelsius);
    printf("Voltage to celsius conversion: \n");
    copyWithConversion(vdata, MAX_VALUES, voltageToCelsius);
    return 0;
}