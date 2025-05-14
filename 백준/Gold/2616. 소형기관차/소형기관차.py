import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
prefix = [0] * (n + 1)
for i in range(1, n + 1):
    prefix[i] = prefix[i - 1] + arr[i - 1]
m = int(input())

dp = [[0 for _ in range(n + 1)] for _ in range(4)]
for i in range(1, 4):
    for j in range(m * i, n + 1):
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - m] + prefix[j] - prefix[j - m])

print(dp[3][n])