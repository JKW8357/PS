import sys
input = sys.stdin.readline
MOD = 900528

letters = list(input().strip())
d = {char: i + 1 for i, char in enumerate(letters)}
password = list(reversed(input().strip()))

ans = d[password[0]] % MOD
for i in range(1, len(password)):
    ans += pow(len(letters), i, MOD) * d[password[i]]
    ans %= MOD

print(ans)