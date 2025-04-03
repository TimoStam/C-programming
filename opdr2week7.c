#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double fahrenheitToCelsius(double fahrenheit){
    return (fahrenheit - 32)*5/9;
}

void main(){
    double fahrenheit = 80.0;
    double celsius = fahrenheitToCelsius(fahrenheit);
    printf("%.1f", celsius);
}