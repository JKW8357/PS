import sys
input = sys.stdin.readline

MOD = 10 ** 9 + 7
a, b, n = map(int, input().split())
print(pow(2 ** 31, n - 1, MOD))