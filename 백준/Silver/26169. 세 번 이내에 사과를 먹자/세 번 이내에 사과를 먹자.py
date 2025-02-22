import sys
input = sys.stdin.readline

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def solve(x, y, count, depth):
    if board[x][y] == 1: count += 1
    if depth <= 3 and count == 2: return True

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < 5 and 0 <= ny < 5:
            if board[nx][ny] == -1 or vis[nx][ny]: continue
            vis[nx][ny] = True
            if solve(nx, ny, count, depth + 1): return True
            vis[nx][ny] = False

    return False

board = [list(map(int, input().split())) for _ in range(5)]
vis = [[False for _ in range(5)] for _ in range(5)]
r, c = map(int, input().split())

vis[r][c] = True
print(1 if solve(r, c, 0, 0) else 0)