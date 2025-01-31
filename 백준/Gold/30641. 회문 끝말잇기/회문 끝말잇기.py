import sys
input = sys.stdin.readline
MOD = 10 ** 9 + 7

l, u = map(int, input().split())

cnt = 0
while l < 3 and l <= u:
    cnt += 1
    l += 1
print('H' if cnt % 2 == 1 else 'A')

for i in range(l, u + 1):
    cnt += pow(26, (i - 1) // 2, MOD)
    cnt %= MOD
print(cnt)