#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COURSES 10

typedef struct {
	char name[20];
	int ECTS;

}Course;

void changeCourse(Course* course[]){
    int input, index = 0;
    do {
        printf("What course do you want to change: ");
        input = scanf_s("%d", &index);
        if (input != 1 || index <-1 || index >=MAX_COURSES){
            printf("Try again\n");
            while (getchar() != '\n');
        }
    } while (input !=1 || index <-1 || index >=MAX_COURSES);
    printf("%d\n", index);

    printf("What would the new course be: ");
    scanf_s("%19s", course[index]->name, 20);
}

void main (){
    Course* courses[MAX_COURSES];
    for (int i =0; i<MAX_COURSES; i++){
        courses[i] = malloc(sizeof(Course));
    }
    int courseCount = 0;
    char courseName[20];
    while (courseCount<MAX_COURSES && scanf_s("%19s", courses[courseCount]->name, 20) == 1){
        printf("Entered course: %19s\n", courses[courseCount]->name);
        courseCount++;
    }
    courseCount = 0;
    changeCourse(courses);
    while (courseCount<MAX_COURSES){
        printf("courses %19s\n", courses[courseCount]->name);
        courseCount++;
    }
    for (int i =0; i<MAX_COURSES; i++){
        free(courses[i]);
    }
}