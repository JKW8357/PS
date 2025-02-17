import sys
input = sys.stdin.readline

n, p, q, x, y = map(int,input().split())
dp = dict()
dp[0] = 1

def solve(i):
    if not i in dp:
        dp[i] = solve(max(i // p - x, 0)) + solve(max(i // q - y, 0))
    return dp[i]

print(solve(n))