import sys
input = sys.stdin.readline

n = int(input())
print(pow(n - 1, 2))
for i in range(2, n + 1):
    print(1, i)