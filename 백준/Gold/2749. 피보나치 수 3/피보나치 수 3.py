import sys
input = sys.stdin.readline
MOD = 10 ** 6

def multiply(m1, m2):
    result = [[0, 0], [0, 0]]
    for i in range(2):
        for j in range(2):
            for k in range(2):
                result[i][j] += m1[i][k] * m2[k][j]
                result[i][j] %= MOD
    return result

def power(m, n):
    result = [[1, 0], [0, 1]]
    while n:
        if n % 2:
            result = multiply(result, m)
            n -= 1
        m = multiply(m, m)
        n //= 2
    return result

n = int(input())
f = [[1, 1], [1, 0]]
ans = power(f, n)
print(ans[0][1])