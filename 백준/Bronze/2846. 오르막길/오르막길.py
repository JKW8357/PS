n = int(input())
height = list(map(int, input().split()))

start = height[0]
max_val = 0

for i in range(1, n):
    if height[i] <= height[i - 1]:
        max_val = max(max_val, height[i - 1] - start)
        start = height[i]

max_val = max(max_val, height[-1] - start)
print(max_val)