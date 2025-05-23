import sys
input = sys.stdin.readline

n = int(input())
d = []
while len(d) < n:
    d.extend(list(map(int, input().split())))
nums = ''.join(map(str, d))

for i in range(1001):
    if not nums.count(str(i)):
        print(i)
        break