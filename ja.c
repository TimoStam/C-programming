#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int id;
	char vak[12];
	int ECTS;
	double cijfer;
}studieResultaat;

int compareName(const void *a, const void *b){
    studieResultaat *resultA = (studieResultaat *)a;
    studieResultaat *resultB = (studieResultaat *)b;

    return strcmp(resultA->vak, resultB->vak);
}

int compareECTS(const void *a, const void *b){
    studieResultaat *resultA = (studieResultaat *)a;
    studieResultaat *resultB = (studieResultaat *)b;

    if (resultA->ECTS > resultB->ECTS){
        return 1;
    } 
    else if(resultB->ECTS > resultA->ECTS){
        return -1;
    } else {
        return 0;
    }
}

int main (){
    studieResultaat results[] = {
        {1, "Math", 9, 4.6},
        {2, "Physics", 6, 8.4},
        {3, "Chemistry", 5, 5.5},
        {4, "Gymnastics", 12, 9.1}
    };
    qsort(results, 4, sizeof(results[0]), compareECTS);
    for (int i = 0; i<sizeof(results)/sizeof(results[0]); i++){
        printf("%d, %s, %d, %.2f\n", 
                results[i].id,
                results[i].vak,
                results[i].ECTS,
                results[i].cijfer);
    }
}