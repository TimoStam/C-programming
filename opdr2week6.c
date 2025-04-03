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
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void removeNodeIndex(node_t **headRef){
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
    int value = temp->data;
    printf("deleted value: %d\n", value);
    current->next = temp->next;
    free(temp);
}

void removeNodeValue(node_t **headRef){
    int value=0;
    if (*headRef != NULL && (*headRef)->data < value){
        node_t *temp = *headRef;
        *headRef = (*headRef)->next;
        free(temp);
        return;
    }
    node_t *current = *headRef;
    while (current != NULL && current->next != NULL && current->next->data >= value){
        current = current->next;
    }
    if (current != NULL && current->next != NULL) {
        node_t *temp = current->next;
        printf("deleted value: %d\n", temp->data);
        current->next = temp->next;
        free(temp);
    }
}

void removeNegatives(node_t **headRef){
    int value=0;
    while (*headRef != NULL && (*headRef)->data < value){
        node_t *temp = *headRef;
        *headRef = (*headRef)->next;
        free(temp);
    }
    node_t *current = *headRef;
    while (current != NULL && current->next != NULL){
        if (current->next->data >= value){
            current = current->next;
        } else {
            node_t *temp = current->next;
            printf("deleted value: %d\n", temp->data);
            current->next = temp->next;
            free(temp);
        }
    }
}

void addNodeIndex(node_t **headRef){
    int index, input, value = 0;
    do {
        printf("Where do you want a new node (after index): \n");
        input = scanf_s("%d", &index);
        if (input != 1 || index < 0 || index >= END){
            printf("Try again\n");
            while (getchar() != '\n');
        }
    } while (input != 1 || index < 0 || index >= END);
    if (*headRef == NULL){
        return;
    }
    node_t *current = *headRef;
    for (int i =0; i<index; i++){
        current = current->next;
    }
    node_t *newNode = (node_t *) malloc(sizeof(node_t));

    do {
        printf("New value: \n");
        input = scanf_s("%d", &value);
        if (input != 1){
            printf("Try again\n");
            while (getchar() != '\n');
        }
    } while (input != 1);
    
    newNode->data = value;
    newNode->next = current->next;
    current->next = newNode;
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
        printf("%d ", numbers[count]);
        count++;
    }
    printf("\n");

    createLinkedList(numbers, &head);
    printList(&head);
    // removeNodeIndex(&head);
    // printList(&head);
    // removeNodeValue(&head);
    // printList(&head);
    // removeNegatives(&head);
    // printList(&head);
    addNodeIndex(&head);
    printList(&head);
}