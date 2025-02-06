import sys
input = sys.stdin.readline
MOD = 10 ** 9 + 7

def multiply(m1, m2):
    n = len(m1)
    m = len(m1[0])
    p = len(m2[0])

    result = [[0] * p for _ in range(n)]
    for i in range(n):
        for j in range(p):
            for k in range(m):
                result[i][j] += m1[i][k] * m2[k][j]
                result[i][j] %= MOD

    return result

def power(m, n):
    result = [[1], [0], [0], [0], [0], [0], [0], [0]]
    while n:
        if n % 2:
            result = multiply(m, result)
            n -= 1
        m = multiply(m, m)
        n //= 2
    return result

d = int(input())
m = [[0, 1, 1, 0, 0, 0, 0, 0],
     [1, 0, 1, 1, 0, 0, 0, 0],
     [1, 1, 0, 1, 1, 0, 0, 0],
     [0, 1, 1, 0, 1, 1, 0, 0],
     [0, 0, 1, 1, 0, 1, 1, 0],
     [0, 0, 0, 1, 1, 0, 0, 1],
     [0, 0, 0, 0, 1, 0, 0, 1],
     [0, 0, 0, 0, 0, 1, 1, 0]]

ans = power(m, d)[0][0] % MOD
print(ans)