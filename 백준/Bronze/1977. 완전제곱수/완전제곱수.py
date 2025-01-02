import math

m = math.ceil(math.sqrt(int(input())))
n = math.floor(math.sqrt(int(input())))

if m >= n:
    print(-1)
    exit()

sum = 0
for i in range(m, n + 1):
    sum += i * i
print(sum, m * m, sep='\n')