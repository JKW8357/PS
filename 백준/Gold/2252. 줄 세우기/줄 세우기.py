from collections import deque
import sys
input = sys.stdin.readline

def topological_sort(n, adj, deg):
    result = []
    q = deque()

    for i in range(1, n + 1):
        if deg[i] == 0:
            q.append(i)

    while q:
        cur = q.popleft()
        result.append(cur)
        for nxt in adj[cur]:
            deg[nxt] -= 1
            if deg[nxt] == 0:
                q.append(nxt)

    if len(result) != n:
        print("Cycle exists!")
    else:
        print(*result)

n, m = map(int, input().split())

adj = {i: [] for i in range(1, n + 1)}
deg = {i: 0 for i in range(1, n + 1)}

for _ in range(m):
    a, b = map(int, input().split())
    adj[a].append(b)
    deg[b] += 1

topological_sort(n, adj, deg)