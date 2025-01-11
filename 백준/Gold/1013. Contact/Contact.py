import re

t = int(input())
pattern = re.compile(r'(100+1+|01)+')

for _ in range(t):
    signal = input()
    print('YES' if re.fullmatch(pattern, signal) else 'NO')