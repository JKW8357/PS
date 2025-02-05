import math
import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

plates_1 = []
prev = arr[0]
cnt = 1
for a in arr[1:]:
    if a == prev:
        cnt += 1
    else:
        if plates_1 and plates_1[-1][0] == prev:
            plates_1[-1] = (prev, plates_1[-1][1] + cnt)
        elif prev == 1 and cnt % 2 == 0:
            plates_1.append((2, cnt // 2))
        else:
            plates_1.append((prev, cnt))
        prev = a
        cnt = 1
if prev == 1 and cnt % 2 == 0:
    plates_1.append((2, cnt // 2))
else:
    plates_1.append((prev, cnt))

plates_2 = []
for plate in plates_1:
    if plates_2 and plates_2[-1][0] == plate[0]:
        plates_2[-1] = (plate[0], plates_2[-1][1] + plate[1])
    else:
        plates_2.append(plate)

p, q, r = 0, 0, 0
total = 0
for i in range(len(plates_2)):
    if plates_2[i][0] == 2:
        tmp_p = plates_2[i - 1][1] if i != 0 else 1
        tmp_q = plates_2[i][1]
        tmp_r = plates_2[i + 1][1] if i != len(plates_2) - 1 else 1
        tmp_total = (tmp_p - 1) // 2 + tmp_q + (tmp_r - 1) // 2
        if tmp_total > total:
            total = tmp_total
            p, q, r = tmp_p, tmp_q, tmp_r

def odd_calc(n):
    power = 1
    while power * 2 <= n:
        power *= 2
    return power

if total == 0:
    print(odd_calc(n))
else:
    print(2 ** (int(math.log2(total) + 1)))