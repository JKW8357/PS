import sys
input = sys.stdin.readline

n = int(input())
if n == 1:
    print('YES')
    print(1)
elif n == 2:
    print('NO')
else:
    print('YES')
    print(1, 3, 2, *(i for i in range(4, n + 1)))