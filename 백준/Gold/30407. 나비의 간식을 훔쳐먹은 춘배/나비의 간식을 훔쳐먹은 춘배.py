import sys
input = sys.stdin.readline

n = int(input())
hp, dist, k = map(int, input().split())
punch = [int(input()) for _ in range(n)]

def solve(hp, dist, i, used_dodge):
    if i >= n: return hp

    next_dodge = -1 if used_dodge == 1 else used_dodge
    damage = lambda d: 0 if used_dodge == 1 else max(punch[i] - d, 0)

    dmg1 = damage(dist) // 2
    ans1 = solve(hp - dmg1, dist, i + 1, next_dodge)

    dmg2 = damage(dist + k)
    ans2 = solve(hp - dmg2, dist + k, i + 1, next_dodge)

    dmg3 = damage(dist)
    ans3 = solve(hp - dmg3, dist, i + 1, 1) if used_dodge == 0 else 0

    return max(ans1, ans2, ans3)

max_hp = solve(hp, dist, 0, 0)
print(max_hp if max_hp > 0 else -1)