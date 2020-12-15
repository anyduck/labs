#include <iostream> // cout
#include <iomanip> // setw
#include <ctime> // time
#include <cmath> // rand

using namespace std;

/**
 *  Повертає матрицю заповнену випадковими числами від -9 до 9.
 *  @param n[out] Вказіник розмірність матриці.
 *  @return Вказівник на динамічний двовимірний масив (матрицю).
 */
int** init_matrix(int*);

/**
 *  Сортує матрицю за спаданням резльтату виклика ключа на рядках.
 *  @param matrix[in, out] Матриця, що буде відсортована.
 *  @param n[in] К-сть рядків і ствопців в матриці.
 *  @param key[in] Функція ключ, за значенням якої сорується матриця. 
 */
void bubble_sort_by_rows(int**, int, int (*)(int[], int));
// void insertion_sort_by_rows(int**, int, int (*)(int[], int));
// void shell_sort_by_rows(int**, int, int (*)(int[], int));
// void selection_sort_by_rows(int**, int, int (*)(int[], int));
// void quick_sort_by_rows(int**, int, int, int, int (*)(int[], int));

/**
 *  Повертає головну діагональ матриці.
 *  @param matrix Матриця, з якої буде взята головна діагональ.
 *  @param n К-сть рядків і ствопців в матриці.
 *  @return Вказіник на динамічний масив з головною діагоналлю.
 */
int* get_main_diagonal(int**, int);

inline int get_first_element(int[], int); // Повертає перший елемент масиву
void print_array(int*, int);  // Виводить одновимірний масив
void print_matrix(int**, int);  // Виводить двовимірний масив
void delete_matrix(int **, int);  // Видаляє динамічний двовимірний масив


int main() {
    int n, **matrix = init_matrix(&n);
    cout << "Початкова матриця:\n"; print_matrix(matrix, n);

    bubble_sort_by_rows(matrix, n, get_first_element);
    cout << "Відсотрована матриця:\n"; print_matrix(matrix, n);

    int *diagonal = get_main_diagonal(matrix, n);
    cout << "Головна діагональ:\n"; print_array(diagonal, n);

    delete[] diagonal;
    delete_matrix(matrix, n);

    return 0;
}

// Повертає матрицю заповнену випадковими числами від -9 до 9.
int** init_matrix(int *n) {
    srand(time(NULL));

    cout << "Введіть розмірність квадратної матриці n: ";
    cin >> *n;

    int **matrix = new int* [*n];
    for (int i = 0; i < *n; i++) {
        matrix[i] = new int [*n];

        for (int j = 0; j < *n; j++)
            matrix[i][j] = rand()%19 - 9;
    }
    return matrix;
}

// Повертає перший елемент масиву
inline int get_first_element(int array[], int n) {
    return array[0];
}

// Повертає головну діагональ матриці.
int* get_main_diagonal(int **matrix, int n) {
    int* diagonal = new int[n];
    for (int i = 0; i < n; i++)
        diagonal[i] = matrix[i][i];
    return diagonal;
}

// Виводить одновимірний масив
void print_array(int *array, int n) {
    for (int i = 0; i < n; i++)
        cout << setw(3) << array[i];
    cout << endl;
}

// Виводить двовимірний масив
void print_matrix(int **matrix, int n) {
    for (int i = 0; i < n; i++)
        print_array(matrix[i], n);
    cout << endl;
}

// Видаляє динамічний двовимірний масив
void delete_matrix(int **matrix, int n) {
    for (int i = 0; i < n; i ++)
        delete[] matrix[i];
    delete[] matrix;
}

// Сортує рядки матриці за спаданням функції-ключа (сортування бульбашкою)
void bubble_sort_by_rows(int **matrix, int n, int (*key)(int[], int)) {
    void swap_arrays(int[], int[], int);

    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-1; j++)
            if ((*key)(matrix[j], n) < (*key)(matrix[j+1], n))
                swap_arrays(matrix[j], matrix[j+1], n);
}

// Сортує рядки матриці за спаданням функції-ключа (сортування вставками)
void insertion_sort_by_rows(int **matrix, int n, int (*key)(int[], int)) {
    void assign_array(int[], int[], int);

    int j, *temp = new int[n];

    for (int i = 1; i < n; i++) {
        assign_array(temp, matrix[i], n);             // temp = matrix[i]
        for (j = i; j >= 0 && ((*key)(matrix[j], n) < (*key)(temp, n)); j--)
            assign_array(matrix[j+1], matrix[j], n);  // matrix[j] = matrix[j-1]
        assign_array(matrix[j], temp, n);             // matrix[j] = temp
    }
    delete[] temp;
}

// Сортує рядки матриці за спаданням функції-ключа (сортування Шела)
void shell_sort_by_rows(int **matrix, int n, int (*key)(int[], int)) {
    void assign_array(int[], int[], int);

    int j, *temp = new int[n];

    for (int gap = n/2; gap > 0; gap /= 2)
        for (int i = gap; i < n; i++) {
            assign_array(temp, matrix[i], n);               // temp = matrix[i]
            for (j = i; j >= gap && ((*key)(matrix[j-gap], n) < (*key)(temp, n)); j -= gap)
                assign_array(matrix[j], matrix[j-gap], n);  // matrix[j] = matrix[j-gap]
            assign_array(matrix[j], temp, n);               // matrix[j] = temp
        }
    delete[] temp;
}

// Сортує рядки матриці за спаданням функції-ключа (сортування вибором)
void selection_sort_by_rows(int** matrix, int n, int (*key)(int[], int)) {
    void swap_arrays(int[], int[], int);

    int max_idx;

    for (int i = 0; i < n-1; i++) {
        max_idx = i;
        for (int j = i+1; j < n; j++)
            if ((*key)(matrix[j], n) > (*key)(matrix[max_idx], n))
                max_idx = j;
        swap_arrays(matrix[i], matrix[max_idx], n);
    }
}

// Сортує рядки матриці за спаданням функції-ключа (швидке сортування)
void quick_sort_by_rows(int **matrix, int n, int low, int high, int (*key)(int[], int)) {
    void swap_arrays(int[], int[], int);

    if (low < high) {
        int *pivot = matrix[high]; // опорний елемент
        int i = low; // в резальтаті стане індексом опорного елементу

        for (int j = low; j <= high-1; j++)
            if ((*key)(matrix[j], n) > (*key)(pivot, n))
                swap_arrays(matrix[i++], matrix[j], n);
        swap_arrays(matrix[i], pivot, n);

        quick_sort_by_rows(matrix, n, low, i - 1, key);
        quick_sort_by_rows(matrix, n, i + 1, high, key);
    }
}

// Міняє місцями два масива
void swap_arrays(int *array1, int *array2, int n) {
    int temp;

    for (int i = 0; i < n; i++) {
       temp = array1[i];
       array1[i] = array2[i];
       array2[i] = temp;
    }
}

// Присвоює першому масиву другий (array1 = array2)
void assign_array(int array1[], int array2[], int n) {
    for (int i = 0; i < n; i++)
       array1[i] = array2[i];
}
