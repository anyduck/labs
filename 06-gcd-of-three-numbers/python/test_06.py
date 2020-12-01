import unittest
from main import gcd


class TestStringMethods(unittest.TestCase):

    def test_common(self):
        self.assertEqual(gcd(42,       56,        112),     14)
        self.assertEqual(gcd(461952,   116298,    10314),   18)
        self.assertEqual(gcd(7966496,  314080416, 98208),   32)
        self.assertEqual(gcd(24826148, 45296490,  7523378), 526)

    def test_zero(self):
        self.assertEqual(gcd(0, 0, 0), 0)
        self.assertEqual(gcd(3, 0, 0), 3)
        self.assertEqual(gcd(0, 6, 0), 6)
        self.assertEqual(gcd(0, 0, 9), 9)
        self.assertEqual(gcd(2, 4, 0), 2)
        self.assertEqual(gcd(3, 0, 6), 3)
        self.assertEqual(gcd(0, 4, 8), 4)

    def test_negative(self):
        self.assertEqual(gcd(81, 21, -18), 3)
        self.assertEqual(gcd(64, -32, 40), 8)
        self.assertEqual(gcd(-99, 66, 18), 3)


if __name__ == '__main__':
    unittest.main()
