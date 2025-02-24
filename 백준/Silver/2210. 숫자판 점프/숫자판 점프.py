import sys
input = sys.stdin.readline

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
board = [list(input().split()) for _ in range(5)]
numbers_list = set()

def dfs(x, y, number):
    if len(number) == 6:
        numbers_list.add(number)
        return

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < 5 and 0 <= ny < 5:
            dfs(nx, ny, number + board[nx][ny])

for i in range(5):
    for j in range(5):
        dfs(i, j, board[i][j])

print(len(numbers_list))
