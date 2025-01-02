n = int(input())
s = input()

state = 0
pushed = False
multitrack_drifting = False
result = 0

for command in s:
    if command == 'P':
        pushed = not pushed
        if state == 1:
            multitrack_drifting = True

    else:
        state += 1

    if state == 2:
        if multitrack_drifting:
            result = 6
        else:
            result = 1 if pushed else 5
        break

print(result)