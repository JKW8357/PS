import sys
input = sys.stdin.readline

n, m, k = map(int, input().split())
if k < n + m - 1:
    print('NO')
else:
    print('YES')
    for i in range(n):
        for j in range(1, m + 1):
            print(i + j, end=' ')
        print('')