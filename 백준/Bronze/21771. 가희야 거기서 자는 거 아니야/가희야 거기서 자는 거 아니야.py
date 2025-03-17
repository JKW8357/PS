import sys
input = sys.stdin.readline

r, c = map(int, input().split())
rg, cg, rp, cp = map(int, input().split())
board = [input().strip() for _ in range(r)]

def find_gp(letter):
    result = 0

    for i in range(r):
        for j in range(c):
            if board[i][j] == letter:
                result += 1

    return result

gahui = find_gp('G')
pillow = find_gp('P')

check = (gahui == rg * cg) and (pillow < rp * cp)
print(int(check))