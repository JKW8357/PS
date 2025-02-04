import heapq
import sys
input = sys.stdin.readline

n = int(input())
lectures = []

pq = []
max_day = 0

for _ in range(n):
    p, d = map(int, input().split())
    max_day = max(max_day, d)
    lectures.append((d, p))

lectures.sort()

ans = 0
for day in range(max_day, 0, -1):
    while lectures and lectures[-1][0] >= day:
        heapq.heappush(pq, -lectures.pop()[1])

    if pq:
        ans += -heapq.heappop(pq)

print(ans)