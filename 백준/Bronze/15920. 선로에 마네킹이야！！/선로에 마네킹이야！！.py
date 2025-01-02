n = int(input())
s = input()

state, pushed, drift = 0, False, False
for command in s:
    if command == 'P':
        pushed = not pushed
        if state == 1:
            drift = True
    else:
        state += 1
    if state == 2:
        break

if state < 2:
    print(0)
elif drift:
    print(6)
else:
    print(1 if pushed else 5)