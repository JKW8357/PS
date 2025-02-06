from itertools import combinations as C
from bisect import bisect_right
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
matches = list(map(int, input().split()))

matches_left = matches[:n // 2]
matches_right = matches[n // 2:]

m1, m2 = [], []
for i in range(len(matches_left) + 1):
    for combo in C(matches_left, i):
        m1.append(sum(combo))

for i in range(len(matches_right) + 1):
    for combo in C(matches_right, i):
        m2.append(sum(combo))

m2.sort()
ans = sum(bisect_right(m2, m - match) for match in m1)
print(ans)