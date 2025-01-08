from itertools import permutations

n = int(input())
l = [str(i) for i in range(1, 10)]
numbers = [''.join(perm) for perm in permutations(l, 3)]

for _ in range(n):
    query, strike, ball = map(int, input().split())
    query = str(query)
    candidates = []
    
    for num in numbers:
        strike_count, ball_count = 0, 0
        for i in range(3):
            if query[i] == num[i]:
                strike_count += 1
            elif query[i] in num:
                ball_count += 1
        if (strike, ball) == (strike_count, ball_count):
            candidates.append(str(num))
    
    numbers = candidates

print(len(numbers))