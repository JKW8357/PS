n = int(input())
arr = sorted(map(int, input().split()))
ans = 0
if n == 1: ans = 1
elif arr[-1] > sum(arr[:-1]): ans = 2 * sum(arr[:-1]) + 1
else: ans = sum(arr)
print(ans)