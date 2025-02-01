import sys
input = sys.stdin.readline

state = [True] * 4000005
def sieve(n):
    state[1] = False
    i = 2
    while i * i <= n:
        if not state[i]:
            i += 1
            continue
        for j in range(i * i, n + 1, i):
            state[j] = False
        i += 1

n = int(input())
sieve(n)

primes = [i for i in range(2, n + 1) if state[i]]

ans = 0
l, r, primes_sum = 0, 0, 0

while r < len(primes) or primes_sum >= n:
    if r < len(primes) and primes_sum < n:
        primes_sum += primes[r]
        r += 1
    elif primes_sum > n:
        primes_sum -= primes[l]
        l += 1
    elif primes_sum == n:
        ans += 1
        primes_sum -= primes[l]
        l += 1

print(ans)