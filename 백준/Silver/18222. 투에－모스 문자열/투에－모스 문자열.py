def solve(k):
    if k == 1: return 0
    i = int(2 ** ((k - 1).bit_length() - 1))
    return 1 - solve(k - i)

k = int(input())
print(solve(k))