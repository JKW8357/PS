n, k = map(int, input().split())
x = list(map(int, input().split()))

cnt, clap = 1, x[0] + k
for i in range(1, n):
    if x[i] > clap:
        clap = x[i] + k
        cnt += 1

print(cnt)