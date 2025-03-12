from collections import deque
import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
dq = deque()
for i in range(n):
    dq.append([arr[i], i + 1]) # tuple X, list

while dq:
    num, idx = dq.popleft()
    print(idx, end=' ')

    if len(dq) == 0: break

    if num > 0:
        for _ in range(num - 1):
            dq.append(dq.popleft())

    else:
        for _ in range(-num):
            dq.appendleft(dq.pop())