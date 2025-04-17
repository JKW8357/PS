import sys
input = sys.stdin.readline

n = int(input())
for _ in range(n):
    x = list(map(int, input().strip()))
    for i in range(len(x) - 1, 0, -1):
        if x[i] >= 5: x[i - 1] = int(x[i - 1]) + 1
        x[i] = 0
    print(*x, sep='')