import sys
input = sys.stdin.readline

n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
query = [list(map(int, input().split())) for _ in range(m)]
diff = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
idx = 0

for i in range(m):
    if query[i][0] == 2: idx = i; break
    q, x1, y1, x2, y2, k = query[i]
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

prefix = [[0] * (n + 1) for _ in range(n + 1)]

for i in range(1, n + 1):
    for j in range(1, n + 1):
        prefix[i][j] = board[i - 1][j - 1] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1]

for i in range(idx, m):
    q, x1, y1, x2, y2 = query[i]
    x1 += 1; y1 += 1; x2 += 1; y2 += 1
    ans = prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1]
    print(ans)