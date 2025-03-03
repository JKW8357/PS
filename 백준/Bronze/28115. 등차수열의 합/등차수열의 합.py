import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))

for i in range(1, n):
    d = a[1] - a[0]
    if d != a[i] - a[i - 1]:
        print('NO')
        exit(0)

print('YES')
print(*a)
print(*(0 for _ in range(n)))