#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int blacklist(char* s) {
	//code die sommige woorden vervangt door *
}

int censuur_print(char* tekst, int (*fp)(char*)) {
	int a = fp(tekst);
	printf("%s", tekst);
	return a;
}

int main(){
    char tekst[] = "Test";
    int result = censuur_print(tekst, blacklist);
    printf("%d\n", result);
    return 0;
}