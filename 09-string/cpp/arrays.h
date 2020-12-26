#include <cstddef> // size_t

using std::size_t;

template <typename T>
void copy_array(T array1[], T array2[], size_t min_size) {
    for (size_t i = 0; i < min_size; i++)
        array1[i] = array2[i];
}

template <typename T>
void double_array(T **array, size_t *max_size) {
    T *temp = new T[2 * *max_size];
    copy_array(temp, *array, *max_size); // temp = array
    delete[] *array;

    *max_size *= 2;
    *array = temp;
}

template <typename T>
void delete_element(T array[], size_t *size, size_t idx) {
    for (size_t i = idx; i < *size-1; i++)
        array[i] = array[i+1];
    (*size)--;
}
