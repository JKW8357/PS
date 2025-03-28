from itertools import combinations as C
import sys
input = sys.stdin.readline

n = int(input())
digits = '9876543210'
result = []

for i in range(1, len(digits) + 1):
    for combo in C(digits, i):
        result.append(int(''.join(combo)))

result.sort()
print(result[n] if n < len(result) else -1)