n = int(input())
arr = list(map(int, input().split()))

ans = 0
for i in range(1, n):
    x = arr[i - 1]
    y = arr[i]
    ans += (x + y) ** 2 + (x - y) ** 2

print(ans)