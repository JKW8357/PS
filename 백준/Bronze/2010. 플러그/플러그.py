import sys
input = sys.stdin.read
print = sys.stdout.write
data = input().split()

n = int(data[0])
sum = 1
for i in range(1, n + 1):
    num = int(data[i])
    sum += num - 1
    
print(str(sum) + '\n')