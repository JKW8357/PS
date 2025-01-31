import sys
input = sys.stdin.readline
MOD = 10 ** 9 + 7

l, u = map(int, input().split())
cnt = 0
multi = 1

if l == 1:
    cnt += 1
    l += 1
if u != 1 and l == 2:
    cnt += 1
    l += 1

print('H' if cnt % 2 == 1 else 'A')

for i in range(3, u + 1):
    if i % 2 == 1:
        multi = (multi * 26) % MOD
    if i >= l:
        cnt = (cnt + multi) % MOD

print(cnt)