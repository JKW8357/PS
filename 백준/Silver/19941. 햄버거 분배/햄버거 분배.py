import sys
input = sys.stdin.readline

n, k = map(int, input().split())
table = list(input().strip())
count = 0

for i in range(n):
    if table[i] == 'P':
        for j in range(max(i - k, 0), min(i + k + 1, n)):
            if table[j] == 'H':
                table[j] = 'X'
                count += 1
                break

print(count)