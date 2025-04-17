import sys
input = sys.stdin.readline

n, k = map(int, input().split())
drone = [0, 0]
obstacles = []
for _ in range(n):
    x, y = map(int, input().split())
    obstacles.append([x, y])
moves = list(input().strip())
directions = {
    'U': (0, 1),
    'D': (0, -1),
    'R': (1, 0),
    'L': (-1, 0),
}

for m in moves:
    dx, dy = directions[m]
    next_pos = [drone[0] + dx, drone[1] + dy]
    if next_pos not in obstacles:
        [drone[0], drone[1]] = next_pos

print(*drone)