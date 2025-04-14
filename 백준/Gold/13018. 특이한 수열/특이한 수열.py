n, k = map(int, input().split())
if k == n: print('Impossible')
else: print(*range(2, n - k + 1), 1, *range(n - k + 1, n + 1))