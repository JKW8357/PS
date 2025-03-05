import sys
input = sys.stdin.readline

tc = int(input())
for _ in range(tc):
    n = int(input())
    if n % 4 == 1: print('1' * (n // 2) + '0' + '1' * (n // 2))
    elif n % 4 == 3: print('1' * (n // 2) + '2' + '1' * (n // 2))
    else: print('1' * n)