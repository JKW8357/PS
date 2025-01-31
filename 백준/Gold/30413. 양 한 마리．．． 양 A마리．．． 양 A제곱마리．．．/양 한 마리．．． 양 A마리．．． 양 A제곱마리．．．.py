MOD = 10 ** 9 + 7
a, b = map(int, input().split())
if a == 1: ans = a * b % MOD
else: ans = ((pow(a, b, MOD) - 1) * pow(a - 1, MOD - 2, MOD)) % MOD
print(ans)