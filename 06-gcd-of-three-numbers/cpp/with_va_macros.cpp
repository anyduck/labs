#include <iostream>
#include <stdarg.h>

using namespace std;

void init(int *, int *, int *);   // введення даних
int gcd(int, int, ...);           // обчислення найбільшого спільного дільника
void browse(int, int, int, int);  // вивдення результатів

int main() {
    int a, b, c,
        result;

    init(&a, &b, &c);
    result = gcd(a, b, c, -1);
    browse(a, b, c, result);

    return 0;
}

void init(int *a, int *b, int *c) {
    cout << "Введіть а: "; cin >> *a;
    cout << "Введіть b: "; cin >> *b;
    cout << "Введіть c: "; cin >> *c;
}

// Знаходить найбільше спільне кратне чисел.
// Використувує власитвість НСД(a, b, c) = НСД(НСД(a, b), c)
int gcd(int a, int b, ...) {

    int gcd(int, int);

    va_list vl;
    int     result,
            current;

    va_start(vl, b);

    result = gcd(a, b);
    while ( (current = va_arg(vl, int)) >= 0 )
        result = gcd(result, current);

    va_end(vl);
    return result;
}

// Знаходить найбільше спільне кратне ДВОХ чисел.
// Використовує алгоритм Евкліда.
int gcd(int a, int b) {
    if (a < b)
        swap(a, b);

    while (b != 0) {
        a %= b;
        swap(a, b);
    }

    return abs(a);
}

void browse(int a, int b, int c, int result) {
    cout << "НСД(" << a << ", " << b << ", " << c << ") = " << result << endl;
}
