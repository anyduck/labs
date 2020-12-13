#include <iostream> // cout
#include <iomanip> // setw
#include <ctime> // time
#include <cmath> // rand

using namespace std;

const int n = 7;
typedef int square_matrix[n][n];

/**
 *  Заповнює матрицю випадковими числами від -9 до 9.
 *  @param matrix[in, out] Матриця, що буде заповнена.
 *  @param n[in] К-сть рядків і ствопців в матриці.
 */
void init(square_matrix, int);

/**
 *  Сортує матрицю за спаданням резльтату виклика ключа на рядках.
 *  @param matrix[in, out] Матриця, що буде відсортована.
 *  @param n[in] К-сть рядків і ствопців в матриці.
 *  @param key[in] Функція ключ, за значенням якої сорується матриця. 
 */
void bubble_sort_by_rows(square_matrix, int, int (*)(int[], int));
// void insertion_sort_by_rows(square_matrix, int, int (*)(int[], int));
// void shell_sort_by_rows(square_matrix, int, int (*)(int[], int));
// void selection_sort_by_rows(square_matrix, int, int (*)(int[], int));
// void quick_sort_by_rows(square_matrix, int, int, int (*)(int[], int));
inline int get_first_element(int[], int);

/**
 *  Повертає головну діагональ матриці.
 *  @param matrix[in] Матриця, з якої буде взята головна діагональ.
 *  @param n[in] К-сть рядків і ствопців в матриці.
 *  @param diagonal[out] Одновимірний масив з елементами головної діагоналі 
 */
void get_main_diagonal(square_matrix, int, int[]);

// Виводить одновимірний масив
void print_array(int[], int);

// Виводить двовимірний масив
void print_matrix(square_matrix, int);


int main() {
    square_matrix matrix;

    init(matrix, n);
    cout << "Початкова матриця:" << endl; print_matrix(matrix, n);

    bubble_sort_by_rows(matrix, n, get_first_element);
    // Варіант з лябмда функцією
    // bubble_sort_by_rows(matrix, n,
    //              [](int row[], int n) {
    //                  return row[0];
    //              });
    cout << "Відсотрована матриця:" << endl; print_matrix(matrix, n);

    int diagonal[n];
    get_main_diagonal(matrix, n, diagonal);
    cout << "Головна діагональ:" << endl; print_array(diagonal, n);

    return 0;
}

// Ініціалізує матрицю випадковими числами від -9 до 9
void init(square_matrix matrix, int n) {
    srand(time(NULL));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = rand()%19 - 9;
}

// Повертає перший елемент масиву
inline int get_first_element(int array[], int n) {
    return array[0];
}

// Сортує рядки матриці за спаданням функції-ключа
void bubble_sort_by_rows(square_matrix matrix, int n, int (*key)(int[], int)) {
    void swap_arrays(int[], int[], int);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if ((*key)(matrix[i], n) > (*key)(matrix[j], n))
                swap_arrays(matrix[i], matrix[j], n);
}

// Міняє місцями елементи двох одномірних масивів
void swap_arrays(int array1[], int array2[], int n) {
    int temp;

    for (int i = 0; i < n; i++) {
       temp = array1[i];
       array1[i] = array2[i];
       array2[i] = temp;
    }
}

// Повертає масив з елементів головної діагоналі квадратної матриці
void get_main_diagonal(square_matrix matrix, int n, int diagonal[]) {
    for (int i = 0; i < n; i++)
        diagonal[i] = matrix[i][i];
}

// Виводить одновимірний масив
void print_array(int array[], int n) {
    for (int j = 0; j < n; j++)
        cout << setw(3) << array[j];
    cout << endl;
}

// Виводить двовимірний масив
void print_matrix(square_matrix matrix, int n) {
    for (int i = 0; i < n; i++)
        print_array(matrix[i], n);
    cout << endl;
}

// Сортує рядки матриці за спаданням функції-ключа
void insertion_sort_by_rows(square_matrix matrix, int n, int (*key)(int[], int)) {
    void insert_array(int[], int[], int);

    int i, j, temp[n];

    for (i = 1; i < n; i++) {
        insert_array(temp, matrix[i], n);

        for (j = i-1; j >= 0 && ((*key)(matrix[j], n) < (*key)(temp, n)); j--)
            insert_array(matrix[j+1], matrix[j], n);
        insert_array(matrix[j+1], temp, n);
    }
}

// Сортує рядки матриці за спаданням функції-ключа
void shell_sort_by_rows(square_matrix matrix, int n, int (*key)(int[], int)) {
    void insert_array(int[], int[], int);

    int gap, i, j, temp[n];

    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++) {
            insert_array(temp, matrix[i], n);

            for (j = i; j >= gap && ((*key)(matrix[j-gap], n) < (*key)(temp, n)); j -= gap)
                insert_array(matrix[j], matrix[j-gap], n);
            insert_array(matrix[j], temp, n);
        }
}

// Вставляє елементи другого масиву в перший
void insert_array(int array1[], int array2[], int n) {
    for (int i = 0; i < n; i++)
       array1[i] = array2[i];
}

// Сортує рядки матриці за спаданням функції-ключа
void selection_sort_by_rows(square_matrix matrix, int n, int (*key)(int[], int)) {
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

// Сортує рядки матриці за спаданням функції-ключа
void quick_sort_by_rows(square_matrix matrix, int low, int high, int (*key)(int[], int)) {
    void swap_arrays(int[], int[], int);

    if (low < high) {
        int *pivot = matrix[high]; // опорний елемент
        int i = low; // в резальтаті стане індексом опорного елементу

        for (int j = low; j <= high-1; j++)
            if ((*key)(matrix[j], n) > (*key)(pivot, n))
                swap_arrays(matrix[i++], matrix[j], n);
        swap_arrays(matrix[i], pivot, n);

        quick_sort_by_rows(matrix, low, i - 1, key);
        quick_sort_by_rows(matrix, i + 1, high, key);
    }
}
