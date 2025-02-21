import sys
input = sys.stdin.readline

n = int(input())
adj = [list() for i in range(n + 1)]
vis = [False] * (n + 1)
a, b = map(int, input().split())
m = int(input())

for _ in range(m):
    p, c = map(int, input().split())
    adj[p].append(c)
    adj[c].append(p)

def dfs(cur, target, length):
    if cur == target: return length
    vis[cur] = True
    for nxt in adj[cur]:
        if vis[nxt]: continue
        result = dfs(nxt, target, length + 1)
        if result != -1: return result
    return -1

print(dfs(a, b, 0))