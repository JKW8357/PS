a, b = map(int, input().split())
ans = 0
if b < 4:
    ans = 0
else:
    a = max(a, 4) + (max(a, 4) % 2)
    b -= b % 2
    ans = ((b - a) // 2 + 1) * (a + b) // 2
print(ans)