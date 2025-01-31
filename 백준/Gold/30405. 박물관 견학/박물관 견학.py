import sys
input = sys.stdin.readline

n, m = map(int, input().split())
dist = []

for _ in range(n):
    plan = list(map(int, input().split()))
    dist.append(plan[1])
    dist.append(plan[-1])

dist.sort()
print(dist[n - 1])