#include <cstddef> // size_t
#include <string> // string

using std::string, std::size_t;

/**
 *  Розділяє рядок на слова або за заданими роздільниками (пробіл за замовчуванням).
 *  @param str[in] Рядок, що буде розділений на слова.
 *  @param size[out] К-сть розділених слів.
 *  @param delimitors[in] Рядок з роздільниками.
 *  @return Масив слів розділених пробілами в рядку.
 */
string *split_into_words(string, size_t*);
string *split_into_words(string, size_t *, string); // С-стиль
string *split_into_words_s(string, size_t *, string); // С++-стиль

/**
 *  Залишає в мисиві лише слова заданої довжини.
 *  @param words[in, out] Масив зі словами, що буде відфільтрований.
 *  @param size[in, out] К-сть слів у масиві.
 *  @param lenght[int] Довжина слів, які потрібно залишити.
 */
void filter_by_length(string[], size_t*, size_t);

// Виводить масив слів через роздільник ", "
void output(string[], size_t);
