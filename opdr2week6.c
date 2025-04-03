#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define END 5
typedef struct node{
    int data;
    struct node *next;
}node_t;

void printList(node_t **headRef){
    node_t *current = *headRef;

    printf("Linked list: \n");
    while (current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }
}

void removeNode(node_t **headRef){
    node_t *current = *headRef;
    node_t *temp = *headRef;
    int input, index = 0;
    do {
        printf("What node do you want to remove: \n");
        input = scanf_s("%d", &index);
        if (input != 1 || index < 0 || index >= END){
            printf("Try again\n");
            while (getchar() != '\n');
        }
    } while (input != 1 || index < 0 || index >= END);

    if (*headRef == NULL){
        return;
    }
    for (int i =0; i<index-1; i++){
        if (current->next == NULL){
            return;
        }
        current = current->next;
    }
    if (current->next == NULL){
        return;
    }
    temp = current->next;
    int val = temp->data;
    printf("deleted value: %d\n", val);
    current->next = temp->next;
    free(temp);
}

void createLinkedList(int numbers[], node_t **headRef){
    int count;
    node_t *current = *headRef;

    for (count = 0; count<END; count++){
        node_t *newNode = (node_t *) malloc(sizeof(node_t));
        newNode->data = numbers[count];
        newNode->next = NULL;

        if (*headRef == NULL){
            *headRef = newNode;
            current = *headRef;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }
    current = *headRef;
}

void main(){
    node_t *head = NULL;

    int numbers[END] = {0,1,2,3,4};
    int count = 0;
    printf("Array of numbers: \n");
    while (count<END){
        printf("%d\n", numbers[count]);
        count++;
    }

    createLinkedList(numbers, &head);
    printList(&head);
    removeNode(&head);
    printList(&head);

}