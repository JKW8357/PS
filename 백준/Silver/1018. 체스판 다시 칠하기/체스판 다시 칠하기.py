n, m = map(int, input().split())
board = [list(input()) for _ in range(n)]

chess = [
    ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
    ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
    ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
    ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
    ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
    ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
    ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
    ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W']
]


def count(row, col):
    cntW, cntB = 0, 0
    for i in range(8):
        for j in range(8):
            if chess[i][j] != board[row + i][col + j]:
                cntW += 1
            if chess[i][7 - j] != board[row + i][col + j]:
                cntB += 1
    return min(cntW, cntB)


ans = 10000
for row in range(n - 7):
    for col in range(m - 7):
        new_ans = count(row, col)
        ans = min(ans, new_ans)

print(ans)