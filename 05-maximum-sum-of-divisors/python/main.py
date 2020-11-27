#!/usr/bin/python3

def main():
    n = int(input("Введіть натуральне n: "))

    # виводимо початок таблиці
    print("n".center(3), "sum".center(7))
    print("=" * 11)

    max_s = 0    # максимальна сума дільників
    max_num = 0  # число, що відповідає максимальній сумі дільників

    # перебір натуральних чисел до n
    for num in range(1, n + 1):
        s = 0    # сума дільників поточно числа num

        # перебір дільників числа num
        for div in range(1, num + 1):
            if num % div == 0:
                s += div

        # збергіємо максимальну суми і число, що їй відповідає
        if s >= max_s:
            max_s = s
            max_num = num

            print(f"{num:3d} {s:7d}")

    print(f"\nМаксимальна сума дільників чисел від 1 до {n} дорівнює {max_s}")


if __name__ == "__main__":
    main()
