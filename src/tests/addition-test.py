import unittest
from algorithms.addition import add

class MyTest(unittest.TestCase):
    def test(self):
        self.assertEqual(add(5,5), 10)
        self.assertEqual(add(1,5), 6)
        self.assertEqual(add(43,5), 48)
        self.assertEqual(add(76,5), 81)
        self.assertEqual(add(0,5), 5)
