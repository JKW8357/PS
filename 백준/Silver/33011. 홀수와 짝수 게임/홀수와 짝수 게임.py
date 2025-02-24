import sys
input = sys.stdin.readline

tc = int(input())
for _ in range(tc):
    n = int(input())
    arr = list(map(int, input().split()))

    odd, even = 0, 0
    for elem in arr:
        if elem % 2: odd += 1
        else: even += 1

    print('amsminn' if max(odd, even) % 2 and odd != even else 'heeda0528')