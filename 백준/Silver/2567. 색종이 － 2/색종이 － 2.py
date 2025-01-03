n = int(input())
paper = [[False for _ in range(101)] for _ in range(101)]

for _ in range(n):
    x, y = map(int, input().split())
    for i in range(x, x + 10):
        for j in range(y, y + 10):
            paper[i][j] = True

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
answer = 0

for x in range(101):
    for y in range(101):
        if paper[x][y]:
            for direction in range(4):
                nx, ny = x + dx[direction], y + dy[direction]
                if 0 <= nx < 101 and 0 <= ny < 101 and not paper[nx][ny]:
                    answer += 1

print(answer)