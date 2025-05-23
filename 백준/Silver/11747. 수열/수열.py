import sys
input = sys.stdin.readline

n = int(input())
d = []
while len(d) < n:
    d.extend(list(map(int, input().split())))

digits = ''.join(map(str, d))
nums = {}

for i in range(n):
    for j in range(i, n):
        num = int(digits[i:j + 1])
        if num not in nums:
            nums[num] = 1

for i in range(n * n):
    if not i in nums:
        print(i)
        break