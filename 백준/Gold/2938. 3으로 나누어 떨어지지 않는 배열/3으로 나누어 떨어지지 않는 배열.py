import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

mod_0, mod_1, mod_2 = [], [], []
for elem in arr:
    if elem % 3 == 0:
        mod_0.append(elem)
    elif elem % 3 == 1:
        mod_1.append(elem)
    else:
        mod_2.append(elem)

if len(mod_0) > len(mod_1) + len(mod_2) + 1:
    print(-1)

elif not mod_0:
    if mod_1 and mod_2:
        print(-1)
    else:
        print(*mod_1, *mod_2)

elif len(mod_0) == 1:
    print(*mod_1, *mod_0, *mod_2)

else:
    seq = [mod_0.pop()]
    while mod_0:
        if mod_1 and len(mod_1) >= len(mod_2):
            seq.append(mod_1.pop())
        else:
            seq.append(mod_2.pop())
        seq.append(mod_0.pop())
    seq = mod_1 + seq + mod_2
    print(*seq)