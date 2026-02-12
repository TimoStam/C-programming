#include <stdio.h>
#include <stdint.h>


int main(){
    double procent[] = {1,2,3,4,5};
    int grens[] = {0,200,300,400,500};
    int salaris = 250;
    int temp = 0;
    double belasting = 0;
    for (int i = sizeof(procent)/sizeof(procent[0]); i > 0; i--){
        if (salaris > grens[i] && salaris < grens[i+1]){
            temp = (salaris - grens[i]);
            salaris -= temp;
            belasting += temp * procent[i];
        }
        if (salaris > grens[sizeof(grens)/sizeof(grens[0])-1]){

        }
    }
}