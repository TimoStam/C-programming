#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define N 2000
#define WINDOW 51

int signal[N];
double coeffs[WINDOW] = {
    -0.026637069922305454,
    -0.021087680355158477,
    -0.015764796484629754,
    -0.010668418310719267,
    -0.005798545833427032,
    -0.0011551790527530382,
    0.0032616820313027114,
    0.007452037418740217,
    0.011415887109559479,
    0.0151532311037605,
    0.018664069401343273,
    0.021948402002307806,
    0.025006228906654094,
    0.02783755011438214,
    0.030442365625491942,
    0.0328206754399835,
    0.03497247955785682,
    0.03689777797911188,
    0.038596570703748716,
    0.0400688577317673,
    0.04131463906316763,
    0.04233391469794973,
    0.043126684636113584,
    0.0436929488776592,
    0.04403270742258656,
    0.04414596027089568,
    0.04403270742258656,
    0.0436929488776592,
    0.04312668463611359,
    0.04233391469794973,
    0.04131463906316764,
    0.0400688577317673,
    0.038596570703748716,
    0.03689777797911189,
    0.03497247955785682,
    0.03282067543998351,
    0.030442365625491945,
    0.027837550114382145,
    0.025006228906654097,
    0.02194840200230781,
    0.018664069401343273,
    0.015153231103760496,
    0.011415887109559474,
    0.00745203741874021,
    0.0032616820313026993,
    -0.001155179052753052,
    -0.005798545833427049,
    -0.010668418310719291,
    -0.01576479648462978,
    -0.021087680355158504,
    -0.026637069922305474
};
  // precomputed savgol_coeffs

void smooth_signal_inplace(int *x, int n, const double *c, int window){
    
    int M = window / 2;
    int i, k;

    /* small rolling buffer */
    double y;

    for (i = M; i < n - M; i++) {
        y = 0.0;

        for (k = -M; k <= M; k++) {
            y += c[k + M] * x[i + k];
        }

        x[i] = y;
    }
}

int main(){
    FILE* fp = fopen("fles3\\meting1\\14.0_f120000d75n6_0.txt", "r");
    if (fp == NULL){
        printf("failed 1\n");
        return 0;
    }
    char c_values[16];
    int count = 0;
    while (count < 2000 && fgets(c_values, sizeof(c_values), fp)){
        signal[count++] = atoi(c_values);
    }

    smooth_signal_inplace(signal, N, coeffs, WINDOW);
    printf("%d\n", signal[1000]);

    FILE* new_values = fopen("filtered_f120000d75n6_1", "w");
    if (new_values == NULL){
        printf("failed 2\n");
        return 0;
    }
    // char filtered_values[N];

    // for (int i = 0; i < sizeof(filtered_values); i++){
    //     filtered_values[i] = signal[i] - '0';
    // }

    // printf("%d", filtered_values[0]);
    char buf[16];
    for (int i = 0; i < sizeof(signal)/sizeof(signal[0]); i++){
        int len = sprintf(buf, "%d\n", signal[i]);
        fputs(buf, new_values);
    }



    fclose(new_values);
    fclose(fp);
}