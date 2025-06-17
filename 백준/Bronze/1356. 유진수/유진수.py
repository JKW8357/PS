def solve(n):
    if len(n) == 1: return False
    for i in range(1, len(n)):
        f, b = 1, 1
        for digit in n[:i]:
            f *= int(digit)
        for digit in n[i:]:
            b *= int(digit)
        if f == b: return True
    return False

print('YES' if solve(input()) else 'NO')