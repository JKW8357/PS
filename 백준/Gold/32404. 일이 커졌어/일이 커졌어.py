n = int(input())
cur = n // 2 + 1
for i in range(1, n + 1):
    print(cur, end=' ')
    cur += (-1) ** i * i