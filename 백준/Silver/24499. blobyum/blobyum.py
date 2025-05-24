n, k = map(int, input().split())
arr = list(map(int, input().split())) * 2

prefix = [0] * (len(arr) + 1)
for i in range(1, 2 * n):
    prefix[i] = arr[i - 1] + prefix[i - 1]

ans = 0
for i in range(1, n + 1):
    ans = max(ans, prefix[i + k - 1] - prefix[i - 1])

print(ans)