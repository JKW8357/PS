import sys
input = sys.stdin.readline

n = int(input())
x, y = [float(0)] * n, [float(0)] * n
for i in range(n):
    x[i], y[i] = map(float, input().split())

m = int(input())
for _ in range(m):
    ans = 0
    p = int(input())
    point = list(map(int, input().split()))
    for i in range(p - 1):
        dx = x[point[i + 1]] - x[point[i]]
        dy = y[point[i + 1]] - y[point[i]]
        ans += (dx ** 2 + dy ** 2) ** 0.5
    print(round(ans))