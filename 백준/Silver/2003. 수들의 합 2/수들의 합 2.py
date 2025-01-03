n, m = map(int, input().split())
numbers = list(map(int, input().split()))

l, r = 0, 0
prefix_sum = 0
answer = 0

while r < n:
    prefix_sum += numbers[r]
    
    while prefix_sum > m:
        prefix_sum -= numbers[l]
        l += 1
        
    if prefix_sum == m:
        answer += 1
        
    r += 1

print(answer)