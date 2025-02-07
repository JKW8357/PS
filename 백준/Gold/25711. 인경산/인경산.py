import sys
input = sys.stdin.readline

n, q = map(int, input().split())
x = list(map(int, input().split()))
y = list(map(int, input().split()))

left = [0] * n
right = [0] * n

for i in range(1, n):
    dx = x[i] - x[i - 1]
    dy = y[i] - y[i - 1]
    dist = (dx * dx + dy * dy) ** 0.5
    
    if dy > 0:
        left[i] = left[i - 1] + dist * 1
        right[i] = right[i - 1] + dist * 3
    elif dy == 0:
        left[i] = left[i - 1] + dist * 2
        right[i] = right[i - 1] + dist * 2
    else:
        left[i] = left[i - 1] + dist * 3
        right[i] = right[i - 1] + dist * 1

for _ in range(q):
    i, j = map(int, input().split())
    if i < j: ans = right[j - 1] - right[i - 1]
    else: ans = left[i - 1] - left[j - 1]
    print(ans)