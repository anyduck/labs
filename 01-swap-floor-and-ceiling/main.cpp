#include <stdio.h>
#include <cmath>


int main() {
    double leg_a, leg_b,  // Катети (a та b)
           hypotenuse,    // Гіпетенуза (c)
           radius;        // Радіус вписаного кола

    printf("Введіть катет (a): "); scanf("%lf", &leg_a);
    printf("Введіть гіпотенузу (c): "); scanf("%lf", &hypotenuse);

    leg_b = sqrt(pow(hypotenuse, 2) - pow(leg_a, 2));  // Катет b за теоремою піфагора
    radius = (leg_a + leg_b - hypotenuse) / 2;         // Радіус вписаного кола

    printf("Радіус вписаного кола (r): %lg\n", radius);

    return 0;
}
