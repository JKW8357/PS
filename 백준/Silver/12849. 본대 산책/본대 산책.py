import sys
input = sys.stdin.readline
MOD = 10 ** 9 + 7

d = int(input())
dp = [0] * 8
dp[0] = 1

for _ in range(d):
    tmp = [0] * 8
    tmp[0] = dp[1] + dp[2]
    tmp[1] = dp[0] + dp[2] + dp[3]
    tmp[2] = dp[0] + dp[1] + dp[3] + dp[4]
    tmp[3] = dp[1] + dp[2] + dp[4] + dp[5]
    tmp[4] = dp[2] + dp[3] + dp[5] + dp[6]
    tmp[5] = dp[3] + dp[4] + dp[7]
    tmp[6] = dp[4] + dp[7]
    tmp[7] = dp[5] + dp[6]

    for i in range(8):
        dp[i] = tmp[i] % MOD

print(dp[0])