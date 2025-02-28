import sys
input = sys.stdin.readline

n = int(input())
expectation = n * (sum(1 / i for i in range(1, n + 1)))
print(expectation)