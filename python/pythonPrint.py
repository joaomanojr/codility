# https://www.hackerrank.com/challenges/python-print/problem

from __future__ import print_function

if __name__ == '__main__':
    n = int(raw_input())

    # list comprehension (https://treyhunner.com/2015/12/python-list-comprehensions-now-in-color/)
    values = [x+1 for x in range(n)]

    for i in values:
        print(i, end='')