#include <iostream> // cout
#include <iomanip> // setw
#include <string> // string
#include <ctime> // time
#include <cmath> // rand

using namespace std;

void init(int [], int size); // ініціалізує початкий масив
void minmax(int [], int size, int &min_idx, int &max_idx); // знаходить індекси мінімального і максимального елементів
template <typename T> void exchange(T &, T &); // змінює місцями дві змінні
void print_array(string title, int [], int size); // виводимо масив
void print_diff(int, int); // виводимо різницю двох чисел

int main() {
    const int size = 10;
    int arr[size];

    init(arr, size);
    print_array("Початковий масив:", arr, size);

    int min, max, min_idx, max_idx;
    minmax(arr, size, min_idx, max_idx);
    print_diff(arr[max_idx], arr[min_idx]);

    exchange(arr[min_idx], arr[size-1]);
    print_array("Кінцевий масив:", arr, size);

    return 0;
}

void init(int arr[], int size) {
    srand(time(NULL));

    for (int i = 0; i < size; i++)
        arr[i] = rand() % 19 -9;
}

void minmax(int arr[], int size, int &min_idx, int &max_idx) {
    min_idx = max_idx = 0;
    int min = arr[min_idx],
        max = arr[max_idx];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
            max_idx = i;
        }
        if (arr[i] < min) {
            min = arr[i];
            min_idx = i;
        }
    }
}

template <typename T>
void exchange(T &a, T &b) {
    int temp = a;
    a = b;
    b = temp;
}

void print_array(string title, int arr[], int size) {
    cout << left << setw(30) << title << right;
    for (int i = 0; i < size; i++)
        cout << setw(3) << arr[i];
    cout << endl;
}

void print_diff(int max, int min) {
    cout << "max - min = " << max << " - " << min << " = " << max-min << endl;
}