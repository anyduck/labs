#include <iostream> // cout
#include <cstddef> // size_t
#include <sstream> // istringstream
#include <cstring> // strtok, strcpy
#include <string> // string

using namespace std;

string *split_into_words(string str, size_t *size) {
    void double_array(string**, size_t*);

    istringstream ss(str);
    string word;

    *size = 0;
    size_t max_size = (str.length() / 10) + 1;
    string *words = new string[max_size];
 
    while (ss >> word) {
        if (*size > max_size-1)
            double_array(&words, &max_size);
        words[(*size)++] = word;
    }
    return words;
}

string *split_into_words(string str, size_t *size, string delimitors) {
    void double_array(string**, size_t*);

    const char *delims = delimitors.c_str(); // Створуємо const рядок в С-стилі зі string
    char s[str.length()]; strcpy(s, str.c_str()); // Створуємо mutable рядок в С-стилі зі string

    *size = 0;
    size_t max_size = (str.length() / 10) + 1;
    string *words = new string[max_size];
 
    char *ptr = strtok(s, delims);
    while (ptr != NULL) {
        if (*size > max_size-1)
            double_array(&words, &max_size);
        words[(*size)++] = string(ptr);
        ptr = strtok(NULL, delims);
    }
    return words;
}

void filter_by_length(string words[], size_t *size, size_t length) {
    void delete_element(string[], size_t*, size_t);

    for (ssize_t i = *size-1; i >= 0; i--)
        if (words[i].length() != length)
            delete_element(words, size, i);
}

void output(string words[], size_t size) {
    if (size != 0) {
        for (size_t i = 0; i < size-1; i++)
            cout << words[i] << ", ";
        cout << words[size-1] << endl;
    }
}

void double_array(string **array, size_t *max_size) {
    void copy_array(string[], string[], size_t);

    string *temp = new string[2 * *max_size];
    copy_array(temp, *array, *max_size); // temp = array
    delete[] *array;

    *max_size *= 2;
    *array = temp;
}

void copy_array(string array1[], string array2[], size_t min_size) {
    for (size_t i = 0; i < min_size; i++)
        array1[i] = array2[i];
}

void delete_element(string array[], size_t *size, size_t idx) {
    for (size_t i = idx; i < *size-1; i++)
        array[i] = array[i+1];
    (*size)--;
}
