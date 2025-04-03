#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define END 5
typedef struct node{
    int data;
    struct node *next;
}node_t;

void linkedList(int numbers[]){
    int count;
    node_t *head = NULL;
    node_t *current = head;

    for (count = 0; count<END; count++){
        node_t *newNode = (node_t *) malloc(sizeof(node_t));
        newNode->data = numbers[count];
        newNode->next = NULL;

        if (head == NULL){
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }
    current = head;

    while (current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }
}

void main(){
    int numbers[END] = {0,1,2,3,4};
    int count = 0;
    printf("Array of numbers: \n");
    while (count<END){
        printf("%d\n", numbers[count]);
        count++;
    }
    count = 0;

    printf("Linked list: \n");
    linkedList(numbers);
}