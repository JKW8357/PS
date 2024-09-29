import sys
input = sys.stdin.readline
print = sys.stdout.write

n = int(input())
sum = 1
for _ in range(n):
    num = int(input())
    sum += num - 1

print(str(sum) + '\n')