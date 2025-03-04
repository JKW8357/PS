import sys
input = sys.stdin.readline

n, m, k = map(int, input().split())

dp = [[0 for _ in range(m + 1)] for _ in range(n + 1)]
dp[1][1] = 1

x = (k + m - 1) // m
y = k - (x - 1) * m

def go(st_x, st_y, en_x, en_y):
    for i in range(st_x, en_x + 1):
        for j in range(st_y, en_y + 1):
            if i == st_x and j == st_y: continue
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

if k == 0:
    go(1, 1, n, m)

else:
    go(1, 1, x, y)
    go(x, y, n, m)

print(dp[n][m])