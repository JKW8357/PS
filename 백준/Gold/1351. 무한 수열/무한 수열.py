import sys
input = sys.stdin.readline

n, p, q = map(int,input().split())
dp = {}
dp[0] = 1

def solve(n):
    if not n in dp:
        dp[n] = solve(n // p) + solve(n // q)
    return dp[n]

print(solve(n))