import sys
input = sys.stdin.readline

n, m = map(int, input().split())
k = list(map(int, input().split()))

total = 0
for num in range(1, n + 1):
    for ki in k:
        if num % ki == 0:
            total += num
            break

print(total)