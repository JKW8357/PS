import sys
input = sys.stdin.readline

def bfs():
    queue = [(0, 0)]
    vis[0][0] = True

    while queue:
        x, y = queue.pop()
        if board[x][y] == -1: return True
        jump = board[x][y]

        for dx, dy in dir:
            nx, ny = x + jump * dx, y + jump * dy
            if 0 <= nx < n and 0 <= ny < n and not vis[nx][ny]:
                queue.append((nx, ny))
                vis[nx][ny] = True

    return False

n = int(input())
dir = [(0, 1), (1, 0)]
board = [list(map(int, input().split())) for _ in range(n)]
vis = [[False] * n for _ in range(n)]
print('HaruHaru' if bfs() else 'Hing')