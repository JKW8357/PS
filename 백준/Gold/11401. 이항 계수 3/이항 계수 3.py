import sys
input = sys.stdin.readline

mod = int(1e9 + 7)
n, k = map(int, input().split())

def factorial(n):
    result = 1
    for i in range(2, n + 1):
        result = result * i % mod
    return result

num = factorial(n)
denom = (factorial(k) * factorial(n - k)) % mod
ans = num * pow(denom, mod - 2, mod) % mod
print(ans)