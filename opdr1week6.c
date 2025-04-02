#include <stdio.h>
#define MAX_COURSES 10

typedef struct {
	char name[20];
	int ECTS;

}Course;


void main (){
    Course courses[MAX_COURSES];
    char courseName[20];
    int courseCount = 0;
    printf("Enter courses: ");
    while (courseCount<MAX_COURSES && scanf_s("%19s", courses[courseCount].name) == 1){
        printf("Entered course: %19s\n", courses[courseCount].name);
        courseCount++;
    }

}