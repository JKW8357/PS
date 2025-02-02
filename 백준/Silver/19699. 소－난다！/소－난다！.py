import sys
input = sys.stdin.readline

ans = []
is_prime = [True] * 10005
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

def solve(depth, cnt, current_sum):
    if cnt == m:
        if is_prime[current_sum] and not current_sum in ans:
            ans.append(current_sum)
        return

    if depth == n: return

    solve(depth + 1, cnt, current_sum)
    solve(depth + 1, cnt + 1, current_sum + weights[depth])

sieve(sum(weights))
solve(0, 0, 0)

if ans: print(*sorted(ans))
else: print(-1)