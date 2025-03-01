import sys
input = sys.stdin.readline

def dfs(w, k):
    if vis[k][w]: return
    vis[k][w] = True
    result[w] = True
    if k == n: return

    dfs(w, k + 1)
    dfs(w + weight[k], k + 1)
    dfs(abs(w - weight[k]), k + 1)

n = int(input())
weight = list(map(int, input().split()))
q = int(input())
query = list(map(int, input().split()))
vis = [[False] * 15001 for _ in range(n + 1)]
result = [False] * 15001

dfs(0, 0)

print(*('Y' if q <= 15000 and result[q] else 'N' for q in query))