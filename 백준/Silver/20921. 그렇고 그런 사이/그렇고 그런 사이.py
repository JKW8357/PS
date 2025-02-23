import sys
input = sys.stdin.readline

n, k = map(int, input().split())
numbers = [i for i in range(1, n + 1)]
result = []

for i in range(n):
    if k >= n - i - 1:
        k -= n - i - 1
        result.append(numbers.pop(-1))
    else:
        result.append(numbers.pop(0))

print(*result)