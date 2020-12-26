#include <iostream> // cout
#include <sstream> // istringstream
#include <cstring> // size_t, strtok, strcpy
#include <string> // string, npos

#include "arrays.h" // double_array, delete_element

using namespace std;

// Розділяє рядок на слова за пробілами
string *split_into_words(string str, size_t *size) {

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

// Розділяє рядок на слова за заданими роздільниками (С-стиль)
string *split_into_words(string str, size_t *size, string delimitors) {

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

// Розділяє рядок на слова за заданими роздільниками (С++-стиль)
string *split_into_words_s(string str, size_t *size, string delimitors) {

    *size = 0;
    size_t max_size = (str.length() / 10) + 1;
    string *words = new string[max_size];

    size_t start_pos = str.find_first_not_of(delimitors),
           end_pos;

    while (start_pos != string::npos) {
        if (*size > max_size-1)
            double_array(&words, &max_size);
        end_pos = str.find_first_of(delimitors, start_pos);
        words[(*size)++] = str.substr(start_pos, end_pos-start_pos);
        start_pos = str.find_first_not_of(delimitors, end_pos);
    }
    return words;
}

// Залишає в мисиві лише слова заданої довжини
void filter_by_length(string words[], size_t *size, size_t length) {
    for (size_t i = *size; i-- > 0;) // Баг в привичному записі (переповення i)
        if (words[i].length() != length)
            delete_element(words, size, i);
}

// Виводить масив слів через роздільник ", "
void output(string array[], size_t size) {
    if (size > 0) {
        for (size_t i = 0; i < size-1; i++)
            cout << array[i] << ", ";
        cout << array[size-1] << endl;
    }
}
