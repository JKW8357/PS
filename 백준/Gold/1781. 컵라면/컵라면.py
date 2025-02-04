import heapq
import sys
input = sys.stdin.readline

n = int(input())
tasks = list(tuple(map(int, input().split())) for _ in range(n))
max_day = max(d for d, w in tasks)
pq = []

tasks.sort()

ans = 0
for day in range(max_day, 0, -1):
    while tasks and tasks[-1][0] >= day:
        heapq.heappush(pq, -tasks.pop()[1])
    if pq:
        ans += -heapq.heappop(pq)

print(ans)