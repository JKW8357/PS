import sys
input = sys.stdin.readline
print = sys.stdout.write

for _ in range(3):
    n = int(input().rstrip())
    sum = 0
    for i in range(n):
        num = int(input().rstrip())
        sum += num
    if sum > 0: print('+\n')
    elif sum < 0: print('-\n')
    else: print('0\n')