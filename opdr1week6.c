#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COURSES 10

typedef struct {
	char name[20];
	int ECTS;

}Course;


void main (){
    Course* courses[MAX_COURSES];
    Course courses1[MAX_COURSES];
    printf("%d\n", sizeof(courses1));
    for (int i =0; i<MAX_COURSES; i++){
        courses[i] = malloc(sizeof(Course));
    }
    printf("%d\n", sizeof(courses));
    int courseCount = 0;
    char courseName[20];
    while (courseCount<MAX_COURSES && scanf_s("%19s", courses[courseCount]->name, 20) == 1){
        printf("Entered course: %19s\n", courses[courseCount]->name);
        courseCount++;
    }
    

    for (int i =0; i<MAX_COURSES; i++){
        free(courses[i]);
    }
}