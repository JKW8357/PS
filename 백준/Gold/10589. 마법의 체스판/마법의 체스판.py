import sys
input = sys.stdin.readline

n, m = map(int, input().split())
result = []
for i in range(2, n + 1, 2):
    result.append([i, 1, i, m])
for j in range(2, m + 1, 2):
    result.append([1, j, n, j])
print(len(result))
for res in result:
    print(*res)