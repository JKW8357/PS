MOD = 10 ** 9 + 7
tc = int(input())
for _ in range(tc):
    p, q, r = map(int, input().split())
    print((p + min(q, r) - 1) % MOD)