import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

d, mn = [0] * n, [0] * n
mn[0] = arr[0]

for i in range(1, n):
    mn[i] = min(mn[i - 1], arr[i])
    d[i] = max(d[i - 1], arr[i] - mn[i])

print(*d)