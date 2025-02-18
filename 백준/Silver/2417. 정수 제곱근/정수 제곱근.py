import sys
input = sys.stdin.readline

n = int(input())
lo = -1
hi = sys.maxsize + 1

while lo + 1 < hi:
    mid = (lo + hi) // 2
    if mid ** 2 >= n: hi = mid
    else: lo = mid

print(hi)