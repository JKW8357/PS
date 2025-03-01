import sys
input = sys.stdin.readline

n, k = map(int, input().split())
arr = list(map(int, input().split()))
ans = sys.maxsize

l, r = 0, 0
cnt = 1 if arr[r] == 1 else 0

while r < n:
    if cnt == k:
        ans = min(ans, r - l + 1)
        if arr[l] == 1: cnt -= 1
        l += 1

    else:
        r += 1
        if r < n and arr[r] == 1: cnt += 1

print(ans if ans != sys.maxsize else -1)