import sys
input = sys.stdin.readline

MOD = 10 ** 9 + 7
q = int(input())
for _ in range(q):
    p, n = map(int, input().split())
    print(((pow(p, n, MOD) - 1) * pow(p - 1, MOD - 2, MOD)) % MOD)