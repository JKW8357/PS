import sys
input = sys.stdin.readline
MOD = 10 ** 9 + 7

n, m = map(int, input().split())
dp = [1 if i < m else 0 for i in range(n + 1)]

for i in range(m, n + 1):
    dp[i] = (dp[i - 1] + dp[i - m]) % MOD

print(dp[n])