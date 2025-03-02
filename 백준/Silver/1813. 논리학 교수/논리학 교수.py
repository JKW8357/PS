from collections import Counter
import sys
input = sys.stdin.readline

n = int(input())
counter = Counter(list(map(int, input().split())))

ans = -1
for i in range(n + 1):
    if i == counter[i]:
        ans = max(ans, i)

print(ans)