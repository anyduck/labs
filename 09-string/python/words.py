from string import punctuation


def split_into_words(s: str) -> list[str]:
    """ Розділяє рядок на слова враховуючи розділові знаки. """

    table = s.maketrans(punctuation, " "*len(punctuation))
    return s.translate(table).split()


def get_by_length(words: list[str], length: int) -> list[str]:
    """ Повертає масив лише з тих слів, довжина яких задана. """

    return [word for word in words if len(word) == length]


def output(title: str, words: list[str]) -> None:
    """ Виводить масив слів через роздільник ", " """

    print(title)
    print(*words, sep=", ")
