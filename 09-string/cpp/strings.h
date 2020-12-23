#include <cstddef> // size_t
#include <string> // string

using std::string, std::size_t;

string *split_into_words(string, size_t*); // Розділяє рядок на слова за пробілами
string *split_into_words(string, size_t *, string); // Розділяє рядок на слова за заданими роздільниками
void filter_by_length(string[], size_t*, size_t); // Залишає в масиві лише слова певної довжини
void output(string[], size_t); // Виводить масив слів через роздільник ", "
