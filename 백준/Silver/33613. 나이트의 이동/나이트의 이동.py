n = int(input())
r, c = map(int, input().split())
if n == 3:
    if r == 2 and c == 2: ans = 1
    else: ans = 4
elif n % 2 == 1: ans = n * n // 2 + 1 if (r + c) % 2 == 0 else n * n // 2
else: ans = n * n // 2
print(ans)