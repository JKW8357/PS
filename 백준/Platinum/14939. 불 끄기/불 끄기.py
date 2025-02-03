import copy
import sys
input = sys.stdin.readline

dx = [0, 0, 1, 0, -1]
dy = [0, 1, 0, -1, 0]

def toggle(bulbs, x, y):
    for dxi, dyi in zip(dx, dy):
        nx = x + dxi
        ny = y + dyi
        if 0 <= nx < 10 and 0 <= ny < 10:
            bulbs[nx][ny] = 'O' if bulbs[nx][ny] == '#' else '#'

def check(bulbs, first_row_mask):
    result = 0

    for c in range(10):
        if first_row_mask & (1 << c):
            toggle(bulbs, 0, c)
            result += 1

    for r in range(1, 10):
        for c in range(10):
            if bulbs[r - 1][c] == 'O':
                toggle(bulbs, r, c)
                result += 1

    return result if all(bulb == '#' for bulb in bulbs[9]) else float('inf')

bulbs = [list(input().strip()) for _ in range(10)]
ans = float('inf')

for first_row_mask in range(1 << 10):
    cnt = check(copy.deepcopy(bulbs), first_row_mask)
    ans = min(ans, cnt)

print(ans if ans != float('inf') else -1)