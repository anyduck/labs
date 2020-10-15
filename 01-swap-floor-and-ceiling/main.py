#! /usr/bin/python

def main():
    a = float(input("Введіть число виду ccc.ddd: "))  # Вхіде число виду ccc.ddd

    ccc = int(a)                    # Ціла частина вхідного числа
    ddd = round((a - ccc) * 10**3)  # Дробова частина вхідного чила

    result = ddd + ccc * 10**-3     # Кінцеве число виду ddd.ccc
    print('Кінцеве число виду ddd.ccc:', result)


if __name__ == "__main__":
    main()
