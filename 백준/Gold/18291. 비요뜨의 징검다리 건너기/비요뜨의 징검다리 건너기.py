import sys
input = sys.stdin.readline
MOD = 10 ** 9 + 7

tc = int(input())
for _ in range(tc):
    n = int(input())
    print(pow(2, n - 2, MOD) if n > 1 else 1)