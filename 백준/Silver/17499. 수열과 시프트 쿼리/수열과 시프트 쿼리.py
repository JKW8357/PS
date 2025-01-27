import sys
input = sys.stdin.readline
n, q = map(int, input().split())
arr = list(map(int, input().split()))

start = 0
for _ in range(q):
    query = list(map(int, input().split()))
    if query[0] == 1:
        i, x = query[1], query[2]
        arr[(start + i - 1) % n] += x
    elif query[0] == 2:
        s = query[1]
        start = (start - s) % n
    else:
        s = query[1]
        start = (start + s) % n

result = [arr[(start + i) % n] for i in range(n)]
print(*result)