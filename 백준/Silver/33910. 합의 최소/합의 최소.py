import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
for i in range(n - 2, -1, -1):
    arr[i] = min(arr[i], arr[i + 1])
print(sum(arr))