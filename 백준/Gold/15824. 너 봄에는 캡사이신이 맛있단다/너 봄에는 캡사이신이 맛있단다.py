import sys
input = sys.stdin.readline
MOD = 10 ** 9 + 7

n = int(input())
menus = sorted(list(map(int, input().split())))
total = 0

for i, menu in enumerate(menus):
    total += (pow(2, i, MOD) - pow(2, n - 1 - i, MOD)) * menu
    total %= MOD

print(total)