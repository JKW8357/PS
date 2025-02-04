import sys
input = sys.stdin.readline

n = int(input())
numbers = list(map(int, input().split()))
max_value = max(numbers)
seive = set(numbers)
scores = {num: 0 for num in numbers}

for i in seive:
    for j in range(2 * i, max_value + 1, i):
        if j in seive:
            scores[i] += 1
            scores[j] -= 1

print(*[scores[num] for num in numbers])