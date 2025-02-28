import sys
input = sys.stdin.readline

n, m = map(int, input().split())
v = n - (m - 2)

for i in range(v - 1):
    print(i, i + 1)

for i in range(v, n):
    print(1, i)