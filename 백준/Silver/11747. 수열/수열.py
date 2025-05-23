import sys
input = sys.stdin.readline

n = int(input())
d = []
while len(d) < n:
    d.extend(list(map(int, input().split())))

digits = ''.join(map(str, d))
nums = set()

for i in range(n):
    for j in range(i, min(i + 6, n)):
        num = int(digits[i:j + 1])
        if num not in nums:
            nums.add(num)

for i in range(n * n):
    if not i in nums:
        print(i)
        break