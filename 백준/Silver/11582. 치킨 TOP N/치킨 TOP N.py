n = int(input())
t = list(map(int, input().split()))
k = int(input())

idx = 0
while idx < n:
    print(*sorted(t[idx : idx + n // k]), end=' ')
    idx += n // k