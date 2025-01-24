n = int(input())
dp = [0] * 101
for i in range(1, n + 1):
    dp[i] = dp[i - 1] + 1
    if i % 3 == 1:
        dp[i] -= 1
print(n + 1 + sum(dp))