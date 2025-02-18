import sys
input = sys.stdin.readline

n, m = map(int, input().split())
height = list(map(int, input().split()))
diff = [0] * (n + 2)

for _ in range(m):
    a, b, k = map(int, input().split())
    diff[a] += k
    diff[b + 1] -= k

for i in range(1, n + 1):
    diff[i] += diff[i - 1]
    height[i - 1] += diff[i]

print(*height)