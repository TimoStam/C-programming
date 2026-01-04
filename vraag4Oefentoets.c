#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char code[8];
	char titel[16];
	int ECTS;
} vak;

typedef struct node{
    vak vak;
    struct node *next;
}node_t;

int main (){
    vak a = {"NSE_PR", "Programmeren", 6};
	vak b = {"NSE_RA", "Rapporteren", 3};
	vak c = {"NSE_EM", "Embedded", 6};
    vak d = {"NSE_NW", "Netwerken", 6};
    node_t node1, node2, node3, node4;

    node1.vak = a;
    node1.next = &node2;

    node2.vak = b;
    node2.next = &node3;

    node3.vak = c;
    node3.next = NULL;

    node4.vak = d;
    node4.next = node2.next;

    node2.next = &node4;
    
    node_t *current = &node1;
    while (current != NULL){
        printf("%s, %s, %d\n", current->vak.code, current->vak.titel, current->vak.ECTS);
        current = current->next;
    }

    return 0;
}