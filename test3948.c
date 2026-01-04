#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "time.h"



int main() {
	srand(time(NULL));
	int x = rand() % 100;
	printf("%d", x);
	

}