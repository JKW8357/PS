n, m = map(int, input().split())

board = []
visited = [[False for _ in range(n)] for _ in range(m)]
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
white, blue = 0, 0

for _ in range(m):
    board.append(input())

def dfs(x, y):
    visited[x][y] = True
    count = 1
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if 0 <= nx < m and 0 <= ny < n:
            if (not visited[nx][ny]) and (board[nx][ny] == board[x][y]):
                count += dfs(nx, ny)
    return count

for i in range(m):
    for j in range(n):
        if not visited[i][j]:
            if board[i][j] == 'W':
                white += dfs(i, j) ** 2
            else:
                blue += dfs(i, j) ** 2

print(white, blue)