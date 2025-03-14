#include <stdio.h>

struct vak{
    char naam[20];
    int ECTS;
};

void changeCourse(struct vak *vakken, int amount){
    int index;
    printf("Index: ");
    scanf("%d", &index);
    if (index < 0 || index >= amount){
        printf("Index is not in scope\n");
        return;
    } else {
        getchar();
        index -= 1;
        printf("Change name: ");
        scanf(" %19[^\n]", vakken[index].naam);
        printf("Change ECTS count: ");
        scanf("%d", &vakken[index].ECTS); 
    }
    return;
}

int main(){
    struct vak vakken[] =
    {
        {"Programmeren C", 6},
        {"Programmeren MC", 9},
        {"Discrete wiskunde", 6}
    };
    int courses = sizeof(vakken)/sizeof(vakken[0]);

    for (int i = 0; i<courses-1; i++){
        printf("%s, ", vakken[i].naam);
    }
    printf("%s\n", vakken[courses-1].naam);
    fflush(stdout);
    changeCourse(vakken, courses);

    for (int i = 0; i<courses-1; i++){
        printf("%s ECTS: %d, ", vakken[i].naam, vakken[i].ECTS);
    }
    printf("%s ECTS: %d\n", vakken[courses-1].naam, vakken[courses-1].ECTS);

}