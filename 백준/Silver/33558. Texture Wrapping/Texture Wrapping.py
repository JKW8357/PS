import sys
input = sys.stdin.readline

n, m = map(int, input().split())
u, v = map(int, input().split())
texture = [list(input().strip()) for _ in range(u)]
board = [[' ' for _ in range(m)] for _ in range(n)]
query = input().strip()

if query == 'clamp-to-edge':
    for j in range(min(m, v)):
        col = [row[j] for row in texture]
        for _ in range(n - len(col)):
            col.append(col[-1])
        for i in range(n):
            board[i][j] = col[i]

    for i in range(n):
        for j in range(v, m):
            board[i][j] = board[i][j - 1]

    for i in range(n):
        print(*board[i], sep='')

elif query == 'repeat':
    for i in range(n):
        for j in range(m):
            board[i][j] = texture[i % u][j % v]

    for i in range(n):
        print(*board[i], sep='')

else:
    def mirror(a, b):
        return a % b if a % (2 * b) < b else (2 * b - 1 - a) % b
    for i in range(n):
        for j in range(m):
            board[i][j] = texture[mirror(i, u)][mirror(j, v)]

    for i in range(n):
        print(*board[i], sep='')