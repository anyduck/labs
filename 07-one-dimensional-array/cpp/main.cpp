#include <stdio.h> // printf
#include <ctime> // time
#include <cmath> // rand

using namespace std;

void init(int [], int size); // ініціалізує початкий масив
void output(int [], int size); // виводимо масив
void minmax(int [], int size, int &min_idx, int &max_idx); // знаходить індекси мінімального і максимального елементів
void exchange(int [], int idx1, int idx2); // змінює місцями два елементи масиву

int main() {
    const int size = 10;
    int arr[size];

    init(arr, size);
    printf("%-30s", "Початковий масив:"); output(arr, size);

    int min, max, min_idx, max_idx;
    minmax(arr, size, min_idx, max_idx);

    min = arr[min_idx]; max = arr[max_idx];
    printf("max - min = %d - %d = %d\n", max, min, max-min);

    exchange(arr, min_idx, size-1);
    printf("%-30s", "Кінцевий масив:"); output(arr, size);

    return 0;
}

void init(int arr[], int size) {
    srand(time(NULL));

    for (int i = 0; i < size; i++)
        arr[i] = rand() % 19 -9;
}

void output(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%3d", arr[i]);
    printf("\n");
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

void exchange(int arr[], int idx1, int idx2) {
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}
