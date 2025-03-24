import sys
input = sys.stdin.readline

n, a = map(int, input().split())
cur = a
ans = 0

while cur <= n:
    ans += n // cur
    cur *= a

print(ans)