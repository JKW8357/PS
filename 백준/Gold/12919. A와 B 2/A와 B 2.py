s = input()
t = input()

def solve(t):
    if s == t:
        return True
    elif len(s) == len(t):
        return False

    if t[-1] == 'A':
        if solve(t[:-1]):
            return True
    if t[0] == 'B':
        if solve(t[1:][::-1]):
            return True

    return False

print(1 if solve(t) else 0)