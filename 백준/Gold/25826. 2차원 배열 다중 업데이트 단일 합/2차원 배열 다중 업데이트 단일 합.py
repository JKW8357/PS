import sys
input = sys.stdin.readline

n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
diff = [[0 for _ in range(n + 1)] for _ in range(n + 1)]

for _ in range(m - 1):
    q, x1, y1, x2, y2, k = map(int, input().split())
    diff[x1][y1] += k
    diff[x2 + 1][y1] -= k
    diff[x1][y2 + 1] -= k
    diff[x2 + 1][y2 + 1] += k

for i in range(n + 1):
    for j in range(1, n + 1):
        diff[i][j] += diff[i][j - 1]

for i in range(1, n + 1):
    for j in range(n + 1):
        diff[i][j] += diff[i - 1][j]

for i in range(n):
    for j in range(n):
        board[i][j] += diff[i][j]

q, x1, y1, x2, y2 = map(int, input().split())
ans = sum(sum(row[y1:y2+1]) for row in board[x1:x2+1])
print(ans)