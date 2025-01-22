n = int(input())
buildings = list(map(int, input().split()))
ans = 0

for i in range(n):
    cnt = 0

    slope = float('inf')
    for j in range(i - 1, -1, -1):
        if slope > (buildings[j] - buildings[i]) / (j - i):
            slope = (buildings[j] - buildings[i]) / (j - i)
            cnt += 1

    slope = -float('inf')
    for j in range(i + 1, n):
        if slope < (buildings[j] - buildings[i]) / (j - i):
            slope = (buildings[j] - buildings[i]) / (j - i)
            cnt += 1

    ans = max(ans, cnt)

print(ans)