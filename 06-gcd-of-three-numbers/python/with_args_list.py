#!/usr/bin/python3
from functools import reduce


def init() -> tuple[int, int, int]:
    """ Вводимо початкові дані. """

    a = int(input("Введіть a: "))
    b = int(input("Введіть b: "))
    c = int(input("Введіть c: "))

    return a, b, c


def gcd(*numbers: int) -> int:
    """ Знаходить найбільше спільне кратне чисел """

    def __gcd(a: int, b: int) -> int:
        """ Знаходить найбільше спільне кратне ДВОХ чисел.

        Використовує алгоритм Евкліда. """

        if a < b:
            a, b = b, a

        while b != 0:
            a %= b
            a, b = b, a

        return abs(a)

    return reduce(__gcd, numbers)


def browse(a: int, b: int, c: int, result: int) -> None:
    """ Виводимо результат обчислень. """

    print(f"НСД{a, b, c} = {result}")


if __name__ == "__main__":
    a, b, c = init()
    result = gcd(a, b, c)
    browse(a, b, c, result)
