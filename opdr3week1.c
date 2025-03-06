#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


static float avg(float grades[6]) {
	float gradeSum = 0.0;
	for (int i = 0; i < 6; ++i) {
		gradeSum += grades[i];
	}
	return gradeSum / 6.0;
}

static int tooLow(float grades[6]) {
	int low=0;
	for (int i =0; i < 6; ++i){
		if (grades[i] < 5.5) {
			low++;
		}
	}
	return low;
}

static int lowGrade(float grades[6]) {
	int amount = 0;
	for (int i = 0; i < (sizeof(grades) / sizeof(grades[0])); ++i) {
		if (grades[i] < 4.0) {
			amount++;
			if (amount > 1){
				return 1;
			}
		}
	}
}

int main() {
	int passed = 1;
	float grades[6] = { 0.0 };
	for (int i = 0; i < (sizeof(grades) / sizeof(grades[0])); ++i) {
		float grade=0.0;
		printf("Enter grade %d: ", i+1);
		scanf("%f", &grade);
		grades[i] = grade;
	}	
	float average = 0.0;
	average = avg(grades);
	printf("The average grade is %.2f.\n", average);
	int low = 0;
	low = tooLow(grades);
	printf("There's %d grades that are too low.\n", low);
	int low2 = 0;
	low2 = lowGrade(grades);
	if (low2 == 1) {
		printf("There are more than 1 grades that are lower than 4.0.\n");
		passed = 0;
	}
	return 0;
}