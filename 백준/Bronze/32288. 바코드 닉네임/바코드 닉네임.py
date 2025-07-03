n = int(input())
print(*('i' if c == 'I' else 'L' for c in input()), sep='')