import sys
input = sys.stdin.readline

n = int(input())
if n ** 0.5 == int(n ** 0.5): print(-1)
else:
    ans = 0
    for i in range(1, int((n / 2) ** 0.5) + 1):
        j = (n - i * i) ** 0.5
        if j == int(j): ans += 1

    for i in range(1, int(n ** 0.5) + 1):
        if n % i == 0:
            j = n // i
            if (i + j) % 2 == 0 and i != j: ans += 1

    print(ans)