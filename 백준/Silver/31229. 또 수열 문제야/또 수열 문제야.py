import sys
input = sys.stdin.readline

n = int(input())
print(*(2 * i + 1 for i in range(n)))