#include <iostream>
#include <cmath>


int main()
{
    double a;

    std::cout << "Введіть число виду ccc.ddd: ";
    scanf("%lf", &a);

    int ccc = (int) a;
    int ddd = (int) round( (a - ccc) * pow(10, 3) );

    double result = ddd + ccc * pow(10, -3);
    printf("%lg\n", result);

    return 0;
}