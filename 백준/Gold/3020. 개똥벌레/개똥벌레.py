from bisect import*
import sys
input = sys.stdin.readline

n, h = map(int, input().split())
up = []
down = []

for i in range(n):
    if i % 2 == 0:
        up.append(int(input()))
    else:
        down.append(int(input()))

up.sort()
down.sort()

result = [0] * (n + 1)
ans = sys.maxsize

for height in range(1, h + 1):
    up_boundary = bisect_left(up, height)
    down_boundary = bisect_left(down, h - height + 1)
    cnt = n - (up_boundary + down_boundary)
    result[cnt] += 1
    ans = min(ans, cnt)

print(ans, result[ans])