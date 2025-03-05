import sys
input = sys.stdin.readline

tc = int(input())
for _ in range(tc):
    n = int(input())
    print('1' + '2' * (n - 2) + '1' if n > 1 else 0)