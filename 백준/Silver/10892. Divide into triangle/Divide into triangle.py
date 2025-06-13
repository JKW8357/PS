n = int(input())
coord = sorted((*map(int, input().split()), i) for i in range(1, 3 * n + 1))
for i in range(3 * n):
    print(coord[i][2], end=' ')
    if (i + 1) % 3 == 0: print()