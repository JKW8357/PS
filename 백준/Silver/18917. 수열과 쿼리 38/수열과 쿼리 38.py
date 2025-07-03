import sys
input = sys.stdin.readline

total, xor = 0, 0
for _ in range(int(input())):
    query = input().split()
    if query[0] == '1':
        x = int(query[1])
        total += x
        xor ^= x
    elif query[0] == '2':
        x = int(query[1])
        total -= x
        xor ^= x
    elif query[0] == '3':
        print(total)
    else:
        print(xor)