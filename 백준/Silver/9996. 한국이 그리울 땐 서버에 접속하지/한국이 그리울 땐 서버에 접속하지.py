import re

n = int(input())
pattern = re.escape(input())
regex = pattern.replace(r'\*', r'.*')

for _ in range(n):
    file_name = input()
    if re.fullmatch(regex, file_name):
        print('DA')
    else:
        print('NE')