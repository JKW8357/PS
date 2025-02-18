fish = '12345'
n, m = map(int, input().split())

for i in range(n):
    for j in range(m):
        print(fish[(i * 2 + j) % 5], end=' ')
    print()