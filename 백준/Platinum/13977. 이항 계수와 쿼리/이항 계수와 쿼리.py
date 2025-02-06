import sys
input = sys.stdin.readline
MOD = 10 ** 9 + 7

factorial = [1] * 4000001
for i in range(2, 4000001):
    factorial[i] = factorial[i - 1] * i % MOD

m = int(input())
for _ in range(m):
    n, k = map(int, input().split())
    num = factorial[n]
    denom = (factorial[k] * factorial[n - k]) % MOD
    ans = num * pow(denom, MOD - 2, MOD) % MOD
    print(ans)