#!/usr/bin/python3

def main():
    a = float(input("Введіть число a: "))
    b = float(input("Введіть число b: "))
    c = float(input("Введіть число c: "))

    # Чи є хоча б одна пара чисел рівних між собою
    is_equal = (a == b) or (a == c) or (b == c)

    result = "є хоча б одна пара" if is_equal else "немає хоча б однієї пари"
    print("Серед цих чисел", result, "рівних між собою")


if __name__ == "__main__":
    main()
