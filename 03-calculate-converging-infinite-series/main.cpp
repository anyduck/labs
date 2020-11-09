#include <stdio.h>
#include <cmath>
#include <limits>

using namespace std;

int main() {
    float x, epsilon;

    printf("Введіть змінну x: "); scanf("%f", &x);
    printf("Введіть точність Ɛ: "); scanf("%f", &epsilon);

    int n = 0;                                         // лічильник поточного елементу
    double fact = 1.0,                                 // факторіал з 2ⁿ
           prev = numeric_limits<double>::infinity(),  // попередній елемент aₙ₋₁
           curr = (pow(x, 2) - 1) / 2,                 // обчислюємо перший елемент (при n=0)
           s = curr;                                   // обчислюємо суму (при n=0)

    printf("n         an                 Δa                 ∑a        \n");
    printf("==========================================================\n");
    printf("%d %18.15lf %18s %18.15lf\n", n, curr, "", s);

    while (fabs(curr - prev) >= epsilon) {                  // поки не достигнута точність Ɛ
        n += 1;

        for (int i = pow(2, n-1) + 1; i <= pow(2, n); i++)  // обчислюємо факторіал 2ⁿ
            fact *= i;

        prev = curr;                                        // зберігаємо попередній елемент
        curr = ((n+1) * pow(x, 2) - 1) / (1 + fact);        // обчислюємо поточний елемент aₙ
        s += curr;                                          // обчислюємо суму ряду

        printf("%d %18.15lf %18.15lf %18.15lf\n", n, curr, curr-prev, s);
    }
    printf("\nСума безкінечного збіжного ряду дорівнює%18.15f\n", s);

    return 0;
}
