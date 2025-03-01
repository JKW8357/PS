import sys
input = sys.stdin.readline

l, p = map(int, input().split())
arr = list(map(int, input().split()))
print(*(elem - l * p for elem in arr))