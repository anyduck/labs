#include <stdio.h>
#include <cmath>


int main() {
    double a;                                        // Вхіде число виду ccc.ddd

    printf("Введіть число виду ccc.ddd: ");
    scanf("%lf", &a);

    int ccc = (int) a;                               // Ціла частина вхідного числа
    int ddd = (int) round( (a - ccc) * pow(10, 3) ); // Дробова частина вхідного чила

    double result = ddd + ccc * pow(10, -3);         // Кінцеве число виду ddd.ccc
    printf("Кінцеве число виду ddd.ccc: %lg\n", result);

    return 0;
}
