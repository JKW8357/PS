n = int(input())
if n == (1 << (len(bin(n + 1)) - 3)) - 1: print(f'1\n{n}')
else: print(f'2\n{(1 << (len(bin(n + 1)) - 2)) - 1 - n}\n{n}')