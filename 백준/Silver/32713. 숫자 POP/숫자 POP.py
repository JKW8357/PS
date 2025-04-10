from itertools import groupby
import sys
input = sys.stdin.readline

n, k = map(int, input().split())
arr = list(map(int, input().split()))

segments = [[key, sum(1 for _ in group)] for key, group in groupby(arr)]

ans = 0
for i in range(len(segments)):
    num = segments[i][0]
    cnt = deleted = 0

    for j in range(i, len(segments)):
        if segments[j][0] != num:
            deleted += segments[j][1]
            if deleted > k: break
        else:
            cnt += segments[j][1]
        ans = max(ans, cnt)

print(ans)