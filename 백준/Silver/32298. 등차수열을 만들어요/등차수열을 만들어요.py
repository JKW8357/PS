n, m = map(int, input().split())
print(*(m * i for i in range(2, n + 2)))