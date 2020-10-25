#include <iostream>
#include <string>

using namespace std;

int main() {
    float a, b, c;  // Вхідні числа a, b, c

    cout << "Введіть число a: "; cin >> a;
    cout << "Введіть число b: "; cin >> b;
    cout << "Введіть число c: "; cin >> c;

    bool is_equal = (a == b) || (a == c) || (b == c);

    string result = (is_equal) ? "є хоча б одна пара" : "немає хоча б однієї пари";
    cout << "Серед цих чисел " << result << " рівних між собою\n";

    return 0;
}