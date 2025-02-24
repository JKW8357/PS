import sys
input = sys.stdin.readline

def dfs(x, y):
    if x == y == n - 1: return True

    for dx, dy in [(0, 1), (1, 0)]:
        nx = x + board[x][y] * dx
        ny = y + board[x][y] * dy
        if 0 <= nx < n and 0 <= ny < n and board[x][y] > 0:
            if dfs(nx, ny): return True

    return False

n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
print('HaruHaru' if dfs(0, 0) else 'Hing')