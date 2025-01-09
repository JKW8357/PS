import re

while True:
    line = input()
    if line == '#': break
    line = re.sub(r'([^a-z0-9\s]|\b\d+\b)', r'', line.lower())
    words = set(line.split())
    print(*sorted(words), sep='\n')
    print()