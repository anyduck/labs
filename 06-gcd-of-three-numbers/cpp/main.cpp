#include <iostream>

using namespace std;

void init(int &, int &, int &);   // введення даних
int gcd(int, int, int);           // обчислення найбільшого спільного дільника
void browse(int, int, int, int);  // вивдення результатів

int main() {
    int a, b, c,
        result;

    init(a, b, c);
    result = gcd(a, b, c);
    browse(a, b, c, result);

    return 0;
}

void init(int &a, int &b, int &c) {
    cout << "Введіть а: "; cin >> a;
    cout << "Введіть b: "; cin >> b;
    cout << "Введіть c: "; cin >> c;
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

// Знаходить найбільше спільне кратне ТРЬОХ чисел.
// Використувує власитвість НСД(a, b, c) = НСД(НСД(a, b), c)
inline int gcd(int a, int b, int c) {
    return gcd(gcd(a, b), c);
}

void browse(int a, int b, int c, int result) {
    cout << "НСД(" << a << ", " << b << ", " << c << ") = " << result << endl;
}
