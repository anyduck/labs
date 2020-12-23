from words import split_into_words, get_by_length, output


def init() -> tuple[str, int]:
    """ Приймає вхідні дані користувача та перевіряє їх на валідність. """

    s = input("Введіть ваш текст: ")
    if len(s) == 0: raise ValueError("Пустий рядок неприпустимий :(")

    length = int(input("Введіть необхідну довжину слів: "))
    if length <= 0: raise ValueError("Довжинна повинна бути більша нуля :(")

    return s, length


if __name__ == "__main__":
    s, length = init()

    words = split_into_words(s)
    output("Всі слова:", words)

    words = get_by_length(words, length)
    output("Відфільтровані слова:", words)
