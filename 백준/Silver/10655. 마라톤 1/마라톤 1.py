n = int(input())
checkpoint = [tuple(map(int, input().split())) for _ in range(n)]

distances = [abs(checkpoint[i][0] - checkpoint[i - 1][0]) + abs(checkpoint[i][1] - checkpoint[i - 1][1]) for i in range(1, n)]
sum_distances = sum(distances)
ans = sum_distances

for i in range(1, n - 1):
    candidate = sum_distances - distances[i - 1] - distances[i] + abs(checkpoint[i + 1][0] - checkpoint[i - 1][0]) + abs(checkpoint[i + 1][1] - checkpoint[i - 1][1])
    ans = min(ans, candidate)

print(ans)