from collections import deque
import sys
input = sys.stdin.readline

n = int(input())
arr = deque(range(1, n + 1))

while arr:
    print(arr.popleft(), end=' ')
    if arr: print(arr.pop(), end=' ')