import sys
input = sys.stdin.readline

n = int(input())
arr = sorted(list(map(int, input().split())))

total = 1
for num in arr:
    if total < num: break
    total += num

print(total)