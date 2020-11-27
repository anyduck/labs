#include <stdio.h>

int main()
{
    unsigned int n,   // порядковий номер елементу, який потрібно обчислити
        sum = 0,      // сума дільників поточно числа
        max_sum = 0,  // максимальна сума дільників
        max_num = 0;  // число, що відповідає максимальні сумі дільників

    printf("Введіть натуральне n: "); scanf("%u", &n);

    // виводимо початок таблиці
    printf(" n    sum  \n");
    printf("===========\n");

    // перебір натуральних чисел до n
    for (unsigned int num = 1; num <= n; num++)
    {
        sum = 0;

        // перебір дільників числа num
        for (unsigned int div = 1; div <= num; div++)
            if (num % div == 0)
                sum += div;

        // збергіємо максимальну суми і число, що їй відповідає
        if (sum >= max_sum)
        {
            max_sum = sum;
            max_num = num;

            printf("%3u %7u\n", num, sum);
        }
    }

    printf("\nМаксимальна сума дільників чисел від 1 до %u дорівнює %u\n", n, max_sum);
    return 0;
}
