import itertools

triangular_number = [ i * (i + 1) // 2 for i in range(1, 50) if i * (i + 1) // 2 < 1000 ]
combinations_sums = set(sum(combo) for combo in itertools.combinations_with_replacement(triangular_number, 3))

t = int(input())
while t > 0:
    t -= 1
    k = int(input())
    print(1 if k in combinations_sums else 0)