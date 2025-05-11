from bisect import bisect_right
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
problems = sorted(map(int, input().split()))
level = list(map(int, input().split()))
size = [0] * len(level)
threshold = [3 * i ** 2 - 3 * i + 1 for i in range(1, 580)]

for i in range(len(size)):
    can_solve = bisect_right(problems, level[i])
    size[i] = bisect_right(threshold, can_solve)

print(*size)