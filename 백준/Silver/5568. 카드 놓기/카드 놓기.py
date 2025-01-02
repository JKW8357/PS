from itertools import permutations

n = int(input())
k = int(input())

numbers = []
for _ in range(n):
    numbers.append(int(input()))

results = set()
for perm in permutations(numbers, k):
    new_number = ''.join(map(str, perm))
    results.add(new_number)

print(len(results))