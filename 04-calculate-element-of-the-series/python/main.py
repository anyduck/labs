#!/usr/bin/python3

def main():
    prev = float(input("Введіть перший елемент ряду x0: "))
    curr = float(input("Введіть другий елемент ряду x1: "))
    q = float(input("Введіть q: "))  # константа, що множиться на xₖ₋₁
    r = float(input("Введіть r: "))  # константа, що множиться на xₖ₋₂
    b = float(input("Введіть b: "))  # константа, що додається
    n = int(input("Введіть порядковий номер елементу n: "))

    # виводимо початок таблиці
    print("n".center(3), "an".center(16))
    print("=" * 20)
    print(f"{0:3d} {prev:16f}")
    print(f"{1:3d} {curr:16f}")

    for k in range(2, n + 1):
        temp = q*curr + r*prev + b  # обчислюємо поточний елемент xₖ
        prev = curr                 # зберігаємо попередній елемент xₖ₋₁
        curr = temp                 # зберігаємо поточний елемент xₖ

        print(f"{k:3d} {curr:16f}")

    print(f"\nЕлемент ряду з порядковим номером n={n} дорівнює {curr}")


if __name__ == "__main__":
    main()
