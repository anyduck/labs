#! /usr/bin/python

def main():
    a = float(input("Введіть число виду ccc.ddd: "))

    ccc = int(a)
    ddd = round((a - ccc) * 10**3)

    result = ddd + ccc * 10**-3  # ddd.ccc
    print(result)


if __name__ == "__main__":
    main()
