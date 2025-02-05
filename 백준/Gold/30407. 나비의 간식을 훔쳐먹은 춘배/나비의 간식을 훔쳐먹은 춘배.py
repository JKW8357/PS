n = int(input())
hp, dist, k = map(int, input().split())
punch = [int(input()) for _ in range(n)]

def solve(hp, dist, punch_idx, used_dodge):
    if punch_idx >= n:
        return hp

    # skill1
    damage = max(punch[punch_idx] - dist, 0) // 2
    if used_dodge == 1:
        used_skill1 = solve(hp, dist, punch_idx + 1, -1)
    else:
        used_skill1 = solve(hp - damage, dist, punch_idx + 1, used_dodge)

    # skill2
    damage = max(punch[punch_idx] - (dist + k), 0)
    if used_dodge == 1:
        used_skill2 = solve(hp, dist + k, punch_idx + 1, -1)
    else:
        used_skill2 = solve(hp - damage, dist + k, punch_idx + 1, used_dodge)

    # skill3
    damage = max(punch[punch_idx] - dist, 0)
    if used_dodge == 0:
        used_skill3 = solve(hp - damage, dist, punch_idx + 1, 1)
    else:
        used_skill3 = 0

    return max(used_skill1, used_skill2, used_skill3)

max_hp = solve(hp, dist, 0, 0)
print(max_hp if max_hp > 0 else -1)