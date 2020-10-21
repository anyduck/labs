#! /usr/bin/python

def main():
    leg_a = float(input("Введіть катет (a): "))            # Катет a
    hypotenuse = float(input("Введіть гіпотенузу (c): "))  # Гіпотенуза

    leg_b = (hypotenuse**2 - leg_a**2) ** 0.5  # Катет b за теоремою піфагора
    radius = (leg_a + leg_b - hypotenuse) / 2  # Радіус вписаного кола
    print("Радіус вписаного кола (r):", radius)


if __name__ == "__main__":
    main()
