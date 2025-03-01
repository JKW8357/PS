import sys
input = sys.stdin.readline

n, k = map(int, input().split())
arr = list(map(int, input().split()))

target_index = list(filter(lambda x: arr[x] == 1, range(len(arr))))
ans = sys.maxsize

for i in range(len(target_index) - k + 1):
    ans = min(ans, target_index[i + k - 1] - target_index[i] + 1)

print(ans if ans != sys.maxsize else -1)