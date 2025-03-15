import sys
input = sys.stdin.readline

n = int(input())
x = input().strip()

prev_1_idx = 0
cur_1_idx = 0
ans = 0 if all(i == '0' for i in x[1:]) else 1

for i in range(1, n):
    if x[i] == '1':
        cur_1_idx = i
        ans += cur_1_idx - prev_1_idx - 1
        prev_1_idx = cur_1_idx

print(ans)