import re
p = re.compile(r'(100+1+|01)+')
print('SUBMARINE' if re.fullmatch(p, input()) else 'NOISE')