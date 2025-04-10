import sys
input = sys.stdin.readline

n, k = map(int, input().split())
arr = list(map(int, input().split()))

ans = 0
for i in range(n):
    num = arr[i]
    cnt = deleted = 0

    for j in range(i, n):
        if arr[j] == num: cnt += 1
        else: deleted += 1
        if deleted > k: break
        ans = max(ans, cnt)

print(ans)