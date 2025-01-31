import sys
input = sys.stdin.readline
MOD = 10 ** 9 + 7

ans = 0
m = int(input())
for _ in range(m):
    n, s = map(int, input().split())
    ans = (ans + s * pow(n, MOD - 2, MOD)) % MOD

print(ans)