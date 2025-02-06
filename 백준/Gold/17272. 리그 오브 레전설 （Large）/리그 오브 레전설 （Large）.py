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

def power(matrix, n):
    size = len(matrix)
    result = [[1] for _ in range(size)]

    while n:
        if n % 2:
            result = multiply(matrix, result)
            n -= 1
        matrix = multiply(matrix, matrix)
        n //= 2

    return result

n, m = map(int, input().split())

transition = [[0 for _ in range(m)] for _ in range(m)]
transition[0][0] = transition[0][m - 1] = 1
for i in range(m - 1):
    transition[i + 1][i] = 1

if n < m: ans = 1
else: ans = power(transition, n - m + 1)[0][0]
print(ans)