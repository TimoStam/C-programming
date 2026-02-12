#include <stdio.h>
double laag = 38883;
double middle = 39543;
double hoog = 78426;
double laagPer = 35.75;
double midPer = 37.56;
double hoogPer = 49.50;

float calculate_income(float income){
	
	float new_income = 0.0;
	if (income < laag){
		new_income += (income/100.0) * laagPer;
		return new_income;
	}

	if (income > laag && income < hoog){
		new_income += (laag/100.0) * laagPer;
		income -= laag;
		new_income += (income/100.0) * midPer;
		return new_income;
	}

	if (income > hoog){
		new_income += (laag/100.0) * laagPer;
		income -= laag;
		new_income += (middle/100.0) * midPer;
		income -= middle;
		new_income += (income/100.0) * hoogPer;
		return new_income;
	}
}

int main(void) {
float income;
if (scanf_s("%f", &income) != 1) {
    printf("Ongeldige invoer\n");
	return 1;
}
float final_income = calculate_income(income);
printf("%.2f\n", final_income);

}
