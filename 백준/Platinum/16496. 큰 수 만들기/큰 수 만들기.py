from functools import cmp_to_key
import sys
input = sys.stdin.readline

def compare(a, b):
    if str(a) + str(b) > str(b) + str(a):
        return -1
    else:
        return 1

n = int(input())
numbers = list(map(int, input().split()))

if all(number == 0 for number in numbers):
    print(0)
else:
    numbers.sort(key=cmp_to_key(compare))
    print(*numbers, sep='')