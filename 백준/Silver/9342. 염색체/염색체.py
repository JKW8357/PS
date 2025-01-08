import re

pattern = re.compile(r'^[A-F]?A+F+C+[A-F]?$')
tc = int(input())
for _ in range(tc):
    print('Infected!' if re.match(pattern, input()) else 'Good')