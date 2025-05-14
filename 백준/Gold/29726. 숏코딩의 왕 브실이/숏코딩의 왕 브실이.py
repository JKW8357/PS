import sys
input = sys.stdin.readline

n, m = map(int, input().split())
arr = list(map(int, input().split()))

prefix_sum = [arr[0]] * n
suffix_max = [arr[-1]] * n
prefix_min = [arr[0]] * n

for i in range(1, n):
    prefix_sum[i] = prefix_sum[i - 1] + arr[i]

for i in range(1, n):
    prefix_min[i] = min(arr[i], prefix_min[i - 1])

for i in range(n - 2, -1, -1):
    suffix_max[i] = max(arr[i], suffix_max[i + 1])

ans = -sys.maxsize
for i in range(m + 1):
    left = prefix_min[i]
    right = suffix_max[n - 1 - (m - i)]
    ans = max(ans, right - left)

print(ans)