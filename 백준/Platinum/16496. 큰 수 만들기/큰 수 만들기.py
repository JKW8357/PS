from functools import cmp_to_key
import sys
input = sys.stdin.readline

def compare(a, b):
    return -1 if a + b > b + a else 1

n = int(input())
numbers = list(input().split())

if all(number == '0' for number in numbers):
    print(0)
else:
    numbers.sort(key=cmp_to_key(compare))
    print(*numbers, sep='')