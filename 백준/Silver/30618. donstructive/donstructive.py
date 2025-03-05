from collections import deque
import sys
input = sys.stdin.readline

n = int(input())
arr = deque()
for i in range(n, 0, -1):
    if i % 2: arr.appendleft(i)
    else: arr.append(i)

print(*arr)