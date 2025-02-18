import sys
input = sys.stdin.readline

n, h = map(int, input().split())
diff = [0] * h

for i in range(0, n, 2):
    diff[0] += 1
    diff[int(input())] -= 1
    diff[h - int(input())] += 1

for i in range(1, h):
    diff[i] += diff[i - 1]

ans = min(diff)
cnt = diff.count(ans)
print(ans, cnt)