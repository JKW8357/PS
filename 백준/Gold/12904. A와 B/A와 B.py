s = input()
t = input()

while len(s) != len(t):
    letter = t[-1]
    t = t[:-1]
    if letter == 'B':
        t = t[::-1]

print(1 if s == t else 0)