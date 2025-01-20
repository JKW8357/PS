n = int(input())
i, ans = 1, 0
while n > 0:
    cnt = min(n, 9 * (10 ** (i - 1)))
    ans += i * cnt
    n -= cnt
    i += 1
print(ans)