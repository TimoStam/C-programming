#include <stdio.h>

int main(void) {
double laag = 38441;
double hoog = 76817;
double laagPer = 35.82;
double midPer = 37.48;
double hoogPer = 49.50;
float inkomen;

if (scanf_s("%f", &inkomen) != 1) {
    printf("Ongeldige invoer\n");
		return 1;
	}
	if (inkomen < laag) {
		printf("%.2f\n", (inkomen / 100.0) * laagPer);
	}
	else if (inkomen >= laag && inkomen < hoog) {
		printf("%.2f\n", (inkomen / 100.0) * midPer);
	}
	else if (inkomen >= hoog) {
		printf("%.2f\n", (inkomen / 100.0) * hoogPer);
	}
}
