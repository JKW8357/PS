from functools import lru_cache
n, m = map(int, input().split())

@lru_cache(maxsize=None)
def solve(n, m):
    if n == 1 != m: return False
    elif n == m: return True
    return solve(n // 2, m) or solve(n - n // 2, m)

print('YES' if solve(n, m) else 'NO')