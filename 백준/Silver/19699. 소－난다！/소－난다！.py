from itertools import combinations as C
import sys
input = sys.stdin.readline

is_prime = [True] * 9005
def sieve(n):
    is_prime[0] = False
    is_prime[1] = False
    i = 2
    while i * i <= n:
        if not is_prime[i]:
            i += 1
            continue
        for j in range(i * i, n + 1, i):
            is_prime[j] = False
        i += 1

n, m = map(int, input().split())
weights = list(map(int, input().split()))
sieve(sum(weights))

ans = set()
for combo in C(weights, m):
    x = sum(combo)
    if is_prime[x]:
        ans.add(x)

if ans: print(*sorted(ans))
else: print(-1)