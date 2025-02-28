import sys
input = sys.stdin.readline

n, dummies = map(int, input().split())

for _ in range(dummies):
    dummy_size = int(input())
    dummy = list(map(int, input().split()))

    for i in range(1, dummy_size):
        if dummy[i - 1] < dummy[i]:
            print('No')
            exit(0)

print('Yes')