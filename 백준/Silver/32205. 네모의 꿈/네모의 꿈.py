from collections import defaultdict
import sys
input = sys.stdin.readline

n = int(input())
d = defaultdict(int)
for _ in range(n):
    a, b, c = map(int, input().split())
    d[a] += 1; d[b] += 1; d[c] += 1
    if any(x >= 2 for x in (d[a], d[b], d[c])):
        print(1)
        exit(0)

print(0)