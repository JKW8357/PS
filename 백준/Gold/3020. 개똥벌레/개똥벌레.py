from collections import defaultdict
from bisect import*
import sys
input = sys.stdin.readline

n, h = map(int, input().split())
up = []
down = []

for i in range(0, n - 1, 2):
    up.append(int(input()))
    down.append(int(input()))

up.sort(reverse=True)
down.sort(reverse=True)

d = defaultdict(int)
for height in range(1, h + 1):
    ob1 = bisect_right(up, -height, key=lambda x: -x)
    ob2 = bisect_right(down, -(h - height + 1), key=lambda x: -x)
    cnt = ob1 + ob2
    d[cnt] += 1

min_val = min(d.keys())
print(min_val, d[min_val])