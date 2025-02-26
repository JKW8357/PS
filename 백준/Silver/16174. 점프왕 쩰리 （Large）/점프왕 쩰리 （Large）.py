import sys
input = sys.stdin.readline

def dfs(x, y):
    if x == n - 1 and y == n - 1: return 1
    if dp[x][y] != -1: return dp[x][y]

    jump = board[x][y]
    if jump == 0: return 0

    dp[x][y] = 0
    for dx, dy in [(0, 1), (1, 0)]:
        nx, ny = x + jump * dx, y + jump * dy
        if 0 <= nx < n and 0 <= ny < n:
            if dfs(nx, ny): dp[x][y] = 1

    return dp[x][y]

n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
dp = [[-1] * n for _ in range(n)]
print("HaruHaru" if dfs(0, 0) else "Hing")