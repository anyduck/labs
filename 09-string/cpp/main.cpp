#include <iostream> // cin, cout, getline
#include <cstddef> // size_t
#include <string> // string

#include "strings.h" // split_into_words_s, filter_by_length, output

using namespace std;

void init(string*, size_t*);
bool is_valid(string, size_t);

int main() {

    string str;
    size_t length;
    init(&str, &length);

    if (is_valid(str, length)) {

        size_t size = 0;
        string *words = split_into_words_s(str, &size, " .,?!'-();");
        cout << "Всі слова:\n"; output(words, size);

        filter_by_length(words, &size, length);
        cout << "Відфільтровані слова:\n"; output(words, size);

        delete[] words;
    }
    return 0;
}

void init(string *str, size_t *length) {
    cout << "Введіть ваш текст: "; getline(cin, *str);
    cout << "Введіть необхідну довжину слів: "; cin >> *length;
}

bool is_valid(string str, size_t length) {
    bool is_valid = true;

    if (str.length() == 0) {
        cerr << "Пустий рядок неприпустимий :(" << endl;
        is_valid = false;
    }
    if (length <= 0) {
        cerr << "Довжинна повинна бути більша нуля :(" << endl;
        is_valid = false;
    }
    return is_valid; 
}
