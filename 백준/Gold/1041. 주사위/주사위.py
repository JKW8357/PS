import sys
input = sys.stdin.readline

n = int(input())
dice = list(map(int, input().split()))

if n == 1:
    print(sum(dice) - max(dice))
else:
    arr = sorted([min(dice[0], dice[5]), min(dice[1], dice[4]), min(dice[2], dice[3])])
    s1 = arr[0]
    s2 = s1 + arr[1]
    s3 = s2 + arr[2]
    ans = 0
    ans += s1 * (n - 2) * (5 * n - 6)
    ans += s2 * (8 * n - 12)
    ans += s3 * 4
    print(ans)