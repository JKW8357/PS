import sys
input = sys.stdin.readline

n, k = map(int, input().split())
arr = list(map(int, input().split()))
ans = sum(arr[i] - arr[0] for i in range(n))
days = sum(1 if arr[i] > arr[0] else 0 for i in range(n))
print(ans, days)