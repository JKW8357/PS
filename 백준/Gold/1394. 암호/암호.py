import sys
input = sys.stdin.readline
MOD = 900528

letters = list(input().strip())
d = {char: i + 1 for i, char in enumerate(letters)}
password = list(reversed(input().strip()))
n = len(letters)
m = [1]

for _ in password:
    m.append(m[-1] * n % MOD)

ans = 0
for i, x in enumerate(password):
    ans += m[i] * d[x]
    ans %= MOD

print(ans)