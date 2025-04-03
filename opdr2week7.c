#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double fahrenheitToCelsius(double fahrenheit){
    return (fahrenheit - 32)*5/9;
}

double voltageToCelsius(double voltage){
    return (voltage*20)-20;
}

void main(){
    double fahrenheit = 80.0;
    double tempCelsius = fahrenheitToCelsius(fahrenheit);
    printf("%.1f\n", tempCelsius);
    double voltage = 2.1;
    double sensCelsius = voltageToCelsius(voltage);
    printf("%.1f\n", sensCelsius);
}