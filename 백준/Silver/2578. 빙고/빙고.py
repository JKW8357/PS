import sys
input = sys.stdin.readline

board = [list(map(int, input().split())) for _ in range(5)]
query = [num for _ in range(5) for num in map(int, input().split())]

def find_coord(num):
    for i in range(5):
        for j in range(5):
            if board[i][j] == num:
                return i, j

def check_row(x):
    return all(board[x][j] == -1 for j in range(5))

def check_col(y):
    return all(board[i][y] == -1 for i in range(5))

def check_diag1():
    return all(board[i][i] == -1 for i in range(5))

def check_diag2():
    return all(board[i][4 - i] == -1 for i in range(5))

def count_bingo():
    count = 0
    for i in range(5):
        if check_row(i):
            count += 1
        if check_col(i):
            count += 1
    if check_diag1():
        count += 1
    if check_diag2():
        count += 1
    return count

def game():
    for idx in range(len(query)):
        x, y = find_coord(query[idx])
        board[x][y] = -1
        if count_bingo() >= 3:
            print(idx + 1)
            return

game()