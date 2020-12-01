#!/usr/bin/python3

def init() -> tuple[int, int, int]:
    """ Вводимо початкові дані. """

    a = int(input("Введіть a: "))
    b = int(input("Введіть b: "))
    c = int(input("Введіть c: "))

    return a, b, c


def gcd(a: int, b: int, c: int = 0) -> int:
    """ Знаходить найбільше спільне кратне ДВОХ або ТРЬОХ чисел. """

    def __gcd(a: int, b: int) -> int:
        """ Знаходить найбільше спільне кратне ДВОХ чисел.

        Використовує алгоритм Евкліда. """

        if a < b:
            a, b = b, a

        while b != 0:
            a %= b
            a, b = b, a

        return abs(a)

    return __gcd(__gcd(a, b), c)


def browse(a: int, b: int, c: int, result: int) -> None:
    """ Виводимо результат обчислень. """

    print(f"НСД{a, b, c} = {result}")


if __name__ == "__main__":
    a, b, c = init()
    result = gcd(a, b, c)
    browse(a, b, c, result)
