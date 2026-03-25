#include <stdio.h>
#include <stdlib.h>

int calculate_score(int pins[10]){

}

int main(){
    int pins1[10], pins2[10] = 0;
    int player_count, current_throw, temp, strike1, strike2 = 0;
    int throws = 2;
    int turns = 10;
    for (int i = 0; i < turns; i++){
        for (int j = 0; i < player_count; i++){
            for (int k = 0; k < throws; k++){
                if (scanf("%d", current_throw) != 0 && current_throw >= 0 && current_throw <= 10){
                    if (0 == j){
                        temp += current_throw;
                        if (10 == temp){
                            printf("Strike\n");
                            pins1[i] = temp;
                            temp = 0;
                            break;
                        }
                    }
                    if (1 == j){
                        temp += current_throw;
                        if (10 == temp){
                            printf("Strike\n");
                            pins2[i] = temp;
                            temp = 0;
                            break;
                    }       
                }
                if (10 == turns){

                }
                }
            }
        }
    }
}