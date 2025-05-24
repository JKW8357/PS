import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

ans = max(arr[0], arr[-1])
for i in range(1, n - 1):
    ans = max(ans, arr[i] + min(arr[i - 1], arr[i + 1]))

print(ans)