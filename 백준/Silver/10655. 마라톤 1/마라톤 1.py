n = int(input())
checkpoint = [tuple(map(int, input().split())) for i in range(n)]

def manhattan(p1, p2):
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

distances = [manhattan(checkpoint[i], checkpoint[i - 1]) for i in range(1, n)]
sum_distances = sum(distances)
ans = sum_distances

for i in range(1, n - 1):
    candidate = sum_distances - distances[i - 1] - distances[i] + manhattan(checkpoint[i + 1], checkpoint[i - 1])
    ans = min(ans, candidate)

print(ans)