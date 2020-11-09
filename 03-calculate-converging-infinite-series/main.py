#!/usr/bin/python3

def main():
    x = float(input("Введіть змінну x: "))
    epsilon = float(input("Введіть точність Ɛ: "))

    n = 0                  # лічильник поточного елементу
    fact = 1               # факторіал з 2ⁿ
    prev = float("inf")    # попередній елемент aₙ₋₁
    curr = (x**2 - 1) / 2  # обчислюємо перший елемент (при n=0)
    s = curr               # обчислюємо суму (при n=0)

    print("n", "an".center(18), "Δa".center(18), "∑a".center(18))
    print("=" * 58)
    print(f"{n} {curr:18.15f} {'':18} {s:18.15f}")

    while abs(curr - prev) >= epsilon:          # поки не достигнута точність Ɛ
        n += 1

        for i in range(2**(n-1) + 1, 2**n + 1): # обчислюємо факторіал 2ⁿ
            fact *= i

        prev = curr                             # зберігаємо попередній елемент
        curr = ((n+1) * x**2 - 1) / (1 + fact)  # обчислюємо поточний елемент aₙ
        s += curr                               # обчислюємо суму ряду

        print(f"{n} {curr:18.15f} {curr-prev:18.15f} {s:18.15f}")

    print(f"\nСума безкінечного збіжного ряду дорівнює{s:18.15f}")


if __name__ == "__main__":
    main()
