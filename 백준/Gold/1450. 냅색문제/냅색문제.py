from itertools import combinations as C
from bisect import bisect_right
import sys
input = sys.stdin.readline

n, c = map(int, input().split())
weights = list(map(int, input().split()))

weights_left = weights[:n // 2]
weights_right = weights[n // 2:]

w1, w2 = [], []
for i in range(len(weights_left) + 1):
    for combo in C(weights_left, i):
        w1.append(sum(combo))

for i in range(len(weights_right) + 1):
    for combo in C(weights_right, i):
        w2.append(sum(combo))

w1.sort()
w2.sort()

ans = sum(bisect_right(w2, c- weight) for weight in w1)
print(ans)