import re
n = int(input())
p = re.compile(r'^(?!.*\.\.|^\..*|.*\.@|.*@\.|.*\.$)[\w.]{6,}@[A-Za-z\d\-.]{3,30}$')
v = set()
for _ in range(n):
    a = input()
    if re.match(p, a):
        u, d = a.split('@')
        u = re.sub(r'\.', r'', u)
        if 6 <= len(u) <= 30:
            a = f'{u}@{d}'
            v.add(a.lower())
print(len(v))