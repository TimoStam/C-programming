#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int id;
	char course[12];
	int ECTS;
	double grade;
}Results;

int compareCourseName(const void *a, const void *b){
    Results *resultA = (Results *)a;
    Results *resultB = (Results *)b;

    return strcmp(resultA->course, resultB->course);
}

void main(){
    Results results[] = {
        {1, "math", 9, 4.0}, 
        {2, "science", 12, 5.2}, 
        {3, "physics", 6, 7.2}, 
        {4, "chemistry", 15, 9.0}
    };
    qsort(results, 4, sizeof(Results), compareCourseName);
    for(int i =0; i<4; i++){
        printf("%s\n", results[i].course);
    }
}