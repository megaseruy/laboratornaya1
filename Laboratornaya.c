/*Халимончиков Лев Ильич*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int main(void)
{
    int n;
    double min, max;

    printf("Input n (number of n): ");
    scanf("%d", &n);
    if (n<0){
        printf("Eror: n must be positive integer\n");
        return 1;
    }

    printf("Input min and max: ");
    scanf("%lf %lf", &min, &max);

        if (min >= max) {
        printf("Eror: min must be < max.\n");
        return 1;
    }

    double* a = malloc(n * sizeof(double));
    int* frac = malloc(n * sizeof(int));
    char* minus = calloc(n + 1, sizeof(int));

    
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        double x = min + (double)rand() / RAND_MAX * (max - min);
        a[i] = x;

        long long cents = llround(x * 1000000.0);
        frac[i] = (cents % 1000000);


        if (frac[i] >= 1 && frac[i] <= n)
            minus[frac[i]] = 1;
    }

    double sum = 0.0;
    printf("\nNo    Number   fractional part\n");
    for (int i = 1; i <= n; i++) {
        printf("%d    %f       %d\n", i, a[i - 1], frac[i - 1]);
        if (minus[i]==1)
            sum -= a[i - 1];
        else
            sum += a[i - 1];
    }

    printf("\nSumm: %f\n", sum);
    return 0;
}
