a, b = map(int, input().split())
if b < 4:
    print(0)
else:
    a = max(a, 4) + (max(a, 4) % 2)
    b -= b % 2
    print(((b - a) // 2 + 1) * (a + b) // 2)